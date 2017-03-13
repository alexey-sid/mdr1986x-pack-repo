/*  1986BE3_UDP
     __   ____  ___    __ ___  ___   __   __
    | |\/| |  )| | )  / |( ( )( ( ) / /   \ \_/
    |_|  |_|_/ |_| \__|_| /_/ (_(_)(_)_)__/_/ \
 *//**
 *  \file  lan.h
 *  \brief  UDP, ARP and ping for 1986BE3.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#ifndef LAN_H
#define LAN_H

#include <inttypes.h>
#include <stdbool.h>
#include "lan-config.h"

/**
 *  \defgroup lan UDP, ARP and ping for 1986BE3.
 *
 *  Usage example:
 *
 *  \code
 *  int main()
 *  {
 *      // Initialize Ethernet controller
 *      lan_init( eth1, MY_MAC, MY_IP, MY_IP_MASK );
 *
 *      // Wait for completion of auto-negotiation...
 *      while ( !lan_autoneg( eth1 ));
 *
 *      while ( 1 ) {
 *          // Receive packets, handle a payload into udp_handle_data()
 *          lan_receive( eth1 );
 *          // Check lan_errno here...
 *
 *          // If the transmit buffer has some free space...
 *          if ( lan_able_transmit( eth1 )) {
 *              // Send data using UDP datagram
 *              udp_transmit( eth1, MY_PORT, TARGET_PORT, TARGET_IP, data, sz );
 *              // Check lan_errno here...
 *          }
 *      }
 *  }
 *
 *  void udp_handle_data( int ifc, uint16_t s_port, uint16_t t_port, ip_addr_t s_ip, uint8_t *data, uint16_t sz )
 *  {
 * 	   // Handle a payload here...
 *  }
 *
 *  \endcode
 *  \{
 */

#ifdef __cplusplus
extern "C" {
#endif

#define SWAP16( x ) ( \
  (( uint16_t )( x ) & 0x00FF ) << 8 \
| (( uint16_t )( x ) & 0xFF00 ) >> 8 \
)

#define SWAP32( x ) ( \
  (( uint32_t )( x ) & 0x000000FF ) << 24 \
| (( uint32_t )( x ) & 0x0000FF00 ) << 8  \
| (( uint32_t )( x ) & 0x00FF0000 ) >> 8  \
| (( uint32_t )( x ) & 0xFF000000 ) >> 24 \
)

#define htons  SWAP16
#define htonl  SWAP32
#define ntohs  SWAP16
#define ntohl  SWAP32

/**
 *  \brief IP address type.
 */
typedef uint32_t ip_addr_t;

#define IP_ADDR( a, b, c, d ) ( \
  (( ip_addr_t )( a )       ) \
| (( ip_addr_t )( b ) <<  8 ) \
| (( ip_addr_t )( c ) << 16 ) \
| (( ip_addr_t )( d ) << 24 ) \
)

#define ETH_TYPE_IP   htons( 0x0800 )
#define ETH_TYPE_ARP  htons( 0x0806 )

/**
 *  \brief Type of Ethernet frame header.
 */
typedef struct {
	mac_addr_t t_mac;
	mac_addr_t s_mac;
	uint16_t   type;
	uint8_t    data[];
} __attribute__((packed)) eth_frame_t;


#define ARP_HW_TYPE_ETH   htons( 0x0001 )
#define ARP_PROT_TYPE_IP  htons( 0x0800 )
#define ARP_OPER_REQUEST  htons( 1 )
#define ARP_OPER_REPLY    htons( 2 )

/**
 *  \brief Type of ARP header.
 */
typedef struct {
	uint16_t   hw_type;
	uint16_t   prot_type;
	uint8_t    hw_len;
	uint8_t    prot_len;
	uint16_t   oper;
	mac_addr_t s_mac;
	ip_addr_t  s_ip;
	mac_addr_t t_mac;
	ip_addr_t  t_ip;
} __attribute__((packed)) arp_packet_t;

/**
 *  \brief Type of ARP cache entry.
 */
typedef struct {
	ip_addr_t  ip;
	mac_addr_t mac;
} arp_cache_entry_t;


#define IP_VERSION           4
#define IP_IHL               5
#define IP_VERSION__IHL      (( IP_VERSION << 4 ) + IP_IHL )

#define IP_PROT_ICMP         1
#define IP_PROT_UDP          17

#define IP_FRAG_0            0x80
#define IP_FRAG_DF           0x40
#define IP_FRAG_MD           0x20
#define IP_FRAG_DETECT_MASK  ( ~( IP_FRAG_0 | IP_FRAG_DF ))

/**
 *  \brief Type of IP header.
 */
typedef struct {
	uint8_t   version__ihl;
	uint8_t   dscp__ecn;
	uint16_t  total_len;
	uint16_t  f_id;
	uint16_t  f_flags__offset;
	uint8_t   ttl;
	uint8_t   prot;
	uint16_t  chsum;
	ip_addr_t s_ip;
	ip_addr_t t_ip;
	uint8_t   data[];
} __attribute__((packed)) ip_packet_t;


#define ICMP_TYPE_ECHO_REPLY  0
#define ICMP_TYPE_ECHO_REQ    8

/**
 *  \brief Type of ICMP echo header.
 */
typedef struct {
	uint8_t  type;
	uint8_t  code;
	uint16_t chsum;
	uint16_t id;
	uint16_t seq;
	uint8_t  data[];
} __attribute__((packed)) icmp_echo_packet_t;


#define UDP_PAYLOAD_LIMIT  ( ETHERNET_PAYLOAD_LIMIT - sizeof( ip_packet_t ) - sizeof( udp_packet_t ))

/**
 *  \brief Type of UDP header.
 */
typedef struct {
	uint16_t s_port;
	uint16_t t_port;
	uint16_t len;
	uint16_t chsum;
	uint8_t  data[];
} __attribute__((packed)) udp_packet_t;


/**
 *  \brief LAN error identifiers.
 */
enum {
	/* all functions */
	LAN_ERR_NONE,
	LAN_ERR_INTERFACE,
	/* udp_transmit */
	LAN_ERR_NO_MAC,
	LAN_ERR_TOO_LONG_PAYLOAD,
	/* lan_receive */
	LAN_ERR_FRAME_TOO_SHORT,
	LAN_ERR_ARP_TOO_SHORT,
	LAN_ERR_IP_TOO_SHORT,
	LAN_ERR_IP_CHECKSUM,
	LAN_ERR_IP_TOTAL_LEN,
	LAN_ERR_UDP_CHECKSUM,
	LAN_ERR_UDP_LEN,
};

/**
 *  \brief Last error.
 */
extern int lan_errno;

/**
 *  \brief Initialize controller of Ethernet interface.
 *  \param ifc Interface ID.
 *  \param mac Interface MAC address.
 *  \param ip Interface IP address.
 *  \param mask Interface subnet mask.
 */
void lan_init( int ifc, mac_addr_t mac, ip_addr_t ip, ip_addr_t mask );

/**
 *  \brief Check auto-negotiation is completed.
 *  \param ifc Interface ID.
 *  \return Completion flag.
 */
bool lan_autoneg( int ifc );

/**
 *  \brief Get a packet from the receive buffer, handle a payload into udp_handle_data().
 *
 *  Check the result of this operation in lan_erron variable.
 *
 *  \param ifc Interface ID.
 *  \return Something-was-received flag.
 */
bool lan_receive( int ifc );

/**
 *  \brief Prototype of a callback function for handling data received into UDP packet.
 *  \param ifc Interface ID.
 *  \param s_port Sender UDP port.
 *  \param t_port Target UDP port.
 *  \param s_ip Sender IP address.
 *  \param data Payload.
 *  \param sz Payload size.
 */
void udp_handle_data( int ifc, uint16_t s_port, uint16_t t_port, ip_addr_t s_ip, uint8_t *data, uint16_t sz );

/**
 *  \brief Check the transmit buffer has free space.
 *  \param ifc Interface ID.
 *  \return Has-some-space flag.
 */
bool lan_able_transmit( int ifc );

/**
 *  \brief Send UDP packet.
 *
 *  Check the result of this operation in lan_erron variable:
 *  - LAN_ERR_NONE              Packet was passed into the transmit buffer.
 *  - LAN_ERR_NO_MAC            Packet was not sent because the target IP address is not found in the ARP cache,
 *                              but an ARP request was sent instead. Try again later.
 *  - LAN_ERR_INTERFACE         Wrong interface ID.
 *  - LAN_ERR_TOO_LONG_PAYLOAD  Wrong payload size.
 *
 *  \param ifc Interface ID.
 *  \param s_port Sender UDP port.
 *  \param t_port Target UDP port.
 *  \param t_ip Target IP address.
 *  \param data Payload.
 *  \param sz Payload size.
 */
void udp_transmit( int ifc, uint16_t s_port, uint16_t t_port, ip_addr_t t_ip, uint8_t *data, uint16_t sz );

/**
 *  \brief Send ARP packet.
 *  \param ifc Interface ID.
 *  \param t_ip Target IP address.
 */
void arp_transmit( int ifc, ip_addr_t ip );

#ifdef __cplusplus
}
#endif

/** \} */

#endif /* LAN_H */
