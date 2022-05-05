#pragma once

#include <GView.hpp>

// PCAPNG -> https://tools.ietf.org/id/draft-gharris-opsawg-pcap-00.html
// PCAP   -> https://wiki.wireshark.org/Development/LibpcapFileFormat

namespace GView::Type::PCAP
{
#define GET_PAIR_FROM_ENUM(x)                                                                                                              \
    {                                                                                                                                      \
        x, (std::string_view(#x).substr(std::string_view(#x).find_last_of(":") + 1))                                                       \
    }

/*
    Global Header
    Packet Header
    Packet Data
    Packet Header
    Packet Data
    ....
*/

enum class Magic : uint32
{
    Identical = 0xA1B2C3D4,
    Swapped   = 0xD4C3B2A1
};

static const std::map<Magic, std::string_view> MagicNames{
    GET_PAIR_FROM_ENUM(Magic::Identical),
    GET_PAIR_FROM_ENUM(Magic::Swapped),
};

enum class LinkType : uint32
{
    NULL_                      = 0,
    ETHERNET                   = 1,
    AX25                       = 3,
    IEEE802_5                  = 6,
    ARCNET_BSD                 = 7,
    SLIP                       = 8,
    PPP                        = 9,
    FDDI                       = 10,
    PPP_HDLC                   = 50,
    PPP_ETHER                  = 51,
    ATM_RFC1483                = 100,
    RAW                        = 101,
    C_HDLC                     = 104,
    IEEE802_11                 = 105,
    FRELAY                     = 107,
    LOOP                       = 108,
    LINUX_SLL                  = 113,
    LTALK                      = 114,
    PFLOG                      = 117,
    IEEE802_11_PRISM           = 119,
    IP_OVER_FC                 = 122,
    SUNATM                     = 123,
    IEEE802_11_RADIOTAP        = 127,
    ARCNET_LINUX               = 129,
    APPLE_IP_OVER_IEEE1394     = 138,
    MTP2_WITH_PHDR             = 139,
    MTP2                       = 140,
    MTP3                       = 141,
    SCCP                       = 142,
    DOCSIS                     = 143,
    LINUX_IRDA                 = 144,
    USER0                      = 147,
    USER1                      = 148,
    USER2                      = 149,
    USER3                      = 150,
    USER4                      = 151,
    USER5                      = 152,
    USER6                      = 153,
    USER7                      = 154,
    USER8                      = 155,
    USER10                     = 156,
    USER11                     = 157,
    USER12                     = 158,
    USER13                     = 159,
    USER14                     = 160,
    USER15                     = 161,
    USER16                     = 162,
    IEEE802_11_AVS             = 163,
    BACNET_MS_TP               = 165,
    PPP_PPPD                   = 166,
    GPRS_LLC                   = 169,
    GPF_T                      = 170,
    GPF_F                      = 171,
    LINUX_LAPD                 = 177,
    MFR                        = 182,
    BLUETOOTH_HCI_H4           = 187,
    USB_LINUX                  = 189,
    PPI                        = 192,
    IEEE802_15_4_WITHFCS       = 195,
    SITA                       = 196,
    ERF                        = 197,
    BLUETOOTH_HCI_H4_WITH_PHDR = 201,
    AX25_KISS                  = 202,
    LAPD                       = 203,
    PPP_WITH_DIR               = 204,
    C_HDLC_WITH_DIR            = 205,
    FRELAY_WITH_DIR            = 206,
    LAPB_WITH_DIR              = 207,
    IPMB_LINUX                 = 209,
    FLEXRAY                    = 210,
    LIN                        = 212,
    IEEE802_15_4_NONASK_PHY    = 215,
    USB_LINUX_MMAPPED          = 220,
    FC_2                       = 224,
    FC_2_WITH_FRAME_DELIMS     = 225,
    IPNET                      = 226,
    CAN_SOCKETCAN              = 227,
    IPV4                       = 228,
    IPV6                       = 229,
    IEEE802_15_4_NOFCS         = 230,
    DBUS                       = 231,
    DVB_CI                     = 235,
    MUX27010                   = 236,
    STANAG_5066_D_PDU          = 237,
    NFLOG                      = 239,
    NETANALYZER                = 240,
    NETANALYZER_TRANSPARENT    = 241,
    IPOIB                      = 242,
    MPEG_2_TS                  = 243,
    NG40                       = 244,
    NFC_LLCP                   = 245,
    INFINIBAND                 = 247,
    SCTP                       = 248,
    USBPCAP                    = 249,
    RTAC_SERIAL                = 250,
    BLUETOOTH_LE_LL            = 251,
    NETLINK                    = 253,
    BLUETOOTH_LINUX_MONITOR    = 254,
    BLUETOOTH_BREDR_BB         = 255,
    BLUETOOTH_LE_LL_WITH_PHDR  = 256,
    PROFIBUS_DL                = 257,
    PKTAP                      = 258,
    EPON                       = 259,
    IPMI_HPM_2                 = 260,
    ZWAVE_R1_R2                = 261,
    ZWAVE_R3                   = 262,
    WATTSTOPPER_DLM            = 263,
    ISO_14443                  = 264,
    RDS                        = 265,
    USB_DARWIN                 = 266,
    SDLC                       = 268,
    LORATAP                    = 270,
    VSOCK                      = 271,
    NORDIC_BLE                 = 272,
    DOCSIS31_XRA31             = 273,
    ETHERNET_MPACKET           = 274,
    DISPLAYPORT_AUX            = 275,
    LINUX_SLL2                 = 276,
    OPENVIZSLA                 = 278,
    EBHSCR                     = 279,
    VPP_DISPATCH               = 280,
    DSA_TAG_BRCM               = 281,
    DSA_TAG_BRCM_PREPEND       = 282,
    IEEE802_15_4_TAP           = 283,
    DSA_TAG_DSA                = 284,
    DSA_TAG_EDSA               = 285,
    ELEE                       = 286,
    Z_WAVE_SERIAL              = 287,
    USB_2_0                    = 288,
    ATSC_ALP                   = 289,
    ETW                        = 290,
    ZBOSS_NCP                  = 292,
};

static const std::map<LinkType, std::string_view> LinkTypeNames{ GET_PAIR_FROM_ENUM(LinkType::NULL_),
                                                                 GET_PAIR_FROM_ENUM(LinkType::ETHERNET),
                                                                 GET_PAIR_FROM_ENUM(LinkType::AX25),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IEEE802_5),
                                                                 GET_PAIR_FROM_ENUM(LinkType::ARCNET_BSD),
                                                                 GET_PAIR_FROM_ENUM(LinkType::SLIP),
                                                                 GET_PAIR_FROM_ENUM(LinkType::PPP),
                                                                 GET_PAIR_FROM_ENUM(LinkType::FDDI),
                                                                 GET_PAIR_FROM_ENUM(LinkType::PPP_HDLC),
                                                                 GET_PAIR_FROM_ENUM(LinkType::PPP_ETHER),
                                                                 GET_PAIR_FROM_ENUM(LinkType::ATM_RFC1483),
                                                                 GET_PAIR_FROM_ENUM(LinkType::RAW),
                                                                 GET_PAIR_FROM_ENUM(LinkType::C_HDLC),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IEEE802_11),
                                                                 GET_PAIR_FROM_ENUM(LinkType::FRELAY),
                                                                 GET_PAIR_FROM_ENUM(LinkType::LOOP),
                                                                 GET_PAIR_FROM_ENUM(LinkType::LINUX_SLL),
                                                                 GET_PAIR_FROM_ENUM(LinkType::LTALK),
                                                                 GET_PAIR_FROM_ENUM(LinkType::PFLOG),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IEEE802_11_PRISM),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IP_OVER_FC),
                                                                 GET_PAIR_FROM_ENUM(LinkType::SUNATM),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IEEE802_11_RADIOTAP),
                                                                 GET_PAIR_FROM_ENUM(LinkType::ARCNET_LINUX),
                                                                 GET_PAIR_FROM_ENUM(LinkType::APPLE_IP_OVER_IEEE1394),
                                                                 GET_PAIR_FROM_ENUM(LinkType::MTP2_WITH_PHDR),
                                                                 GET_PAIR_FROM_ENUM(LinkType::MTP2),
                                                                 GET_PAIR_FROM_ENUM(LinkType::MTP3),
                                                                 GET_PAIR_FROM_ENUM(LinkType::SCCP),
                                                                 GET_PAIR_FROM_ENUM(LinkType::DOCSIS),
                                                                 GET_PAIR_FROM_ENUM(LinkType::LINUX_IRDA),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER0),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER1),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER2),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER3),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER4),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER5),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER6),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER7),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER8),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER10),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER11),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER12),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER13),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER14),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER15),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USER16),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IEEE802_11_AVS),
                                                                 GET_PAIR_FROM_ENUM(LinkType::BACNET_MS_TP),
                                                                 GET_PAIR_FROM_ENUM(LinkType::PPP_PPPD),
                                                                 GET_PAIR_FROM_ENUM(LinkType::GPRS_LLC),
                                                                 GET_PAIR_FROM_ENUM(LinkType::GPF_T),
                                                                 GET_PAIR_FROM_ENUM(LinkType::GPF_F),
                                                                 GET_PAIR_FROM_ENUM(LinkType::LINUX_LAPD),
                                                                 GET_PAIR_FROM_ENUM(LinkType::MFR),
                                                                 GET_PAIR_FROM_ENUM(LinkType::BLUETOOTH_HCI_H4),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USB_LINUX),
                                                                 GET_PAIR_FROM_ENUM(LinkType::PPI),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IEEE802_15_4_WITHFCS),
                                                                 GET_PAIR_FROM_ENUM(LinkType::SITA),
                                                                 GET_PAIR_FROM_ENUM(LinkType::ERF),
                                                                 GET_PAIR_FROM_ENUM(LinkType::BLUETOOTH_HCI_H4_WITH_PHDR),
                                                                 GET_PAIR_FROM_ENUM(LinkType::AX25_KISS),
                                                                 GET_PAIR_FROM_ENUM(LinkType::LAPD),
                                                                 GET_PAIR_FROM_ENUM(LinkType::PPP_WITH_DIR),
                                                                 GET_PAIR_FROM_ENUM(LinkType::C_HDLC_WITH_DIR),
                                                                 GET_PAIR_FROM_ENUM(LinkType::FRELAY_WITH_DIR),
                                                                 GET_PAIR_FROM_ENUM(LinkType::LAPB_WITH_DIR),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IPMB_LINUX),
                                                                 GET_PAIR_FROM_ENUM(LinkType::FLEXRAY),
                                                                 GET_PAIR_FROM_ENUM(LinkType::LIN),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IEEE802_15_4_NONASK_PHY),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USB_LINUX_MMAPPED),
                                                                 GET_PAIR_FROM_ENUM(LinkType::FC_2),
                                                                 GET_PAIR_FROM_ENUM(LinkType::FC_2_WITH_FRAME_DELIMS),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IPNET),
                                                                 GET_PAIR_FROM_ENUM(LinkType::CAN_SOCKETCAN),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IPV4),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IPV6),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IEEE802_15_4_NOFCS),
                                                                 GET_PAIR_FROM_ENUM(LinkType::DBUS),
                                                                 GET_PAIR_FROM_ENUM(LinkType::DVB_CI),
                                                                 GET_PAIR_FROM_ENUM(LinkType::MUX27010),
                                                                 GET_PAIR_FROM_ENUM(LinkType::STANAG_5066_D_PDU),
                                                                 GET_PAIR_FROM_ENUM(LinkType::NFLOG),
                                                                 GET_PAIR_FROM_ENUM(LinkType::NETANALYZER),
                                                                 GET_PAIR_FROM_ENUM(LinkType::NETANALYZER_TRANSPARENT),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IPOIB),
                                                                 GET_PAIR_FROM_ENUM(LinkType::MPEG_2_TS),
                                                                 GET_PAIR_FROM_ENUM(LinkType::NG40),
                                                                 GET_PAIR_FROM_ENUM(LinkType::NFC_LLCP),
                                                                 GET_PAIR_FROM_ENUM(LinkType::INFINIBAND),
                                                                 GET_PAIR_FROM_ENUM(LinkType::SCTP),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USBPCAP),
                                                                 GET_PAIR_FROM_ENUM(LinkType::RTAC_SERIAL),
                                                                 GET_PAIR_FROM_ENUM(LinkType::BLUETOOTH_LE_LL),
                                                                 GET_PAIR_FROM_ENUM(LinkType::NETLINK),
                                                                 GET_PAIR_FROM_ENUM(LinkType::BLUETOOTH_LINUX_MONITOR),
                                                                 GET_PAIR_FROM_ENUM(LinkType::BLUETOOTH_BREDR_BB),
                                                                 GET_PAIR_FROM_ENUM(LinkType::BLUETOOTH_LE_LL_WITH_PHDR),
                                                                 GET_PAIR_FROM_ENUM(LinkType::PROFIBUS_DL),
                                                                 GET_PAIR_FROM_ENUM(LinkType::PKTAP),
                                                                 GET_PAIR_FROM_ENUM(LinkType::EPON),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IPMI_HPM_2),
                                                                 GET_PAIR_FROM_ENUM(LinkType::ZWAVE_R1_R2),
                                                                 GET_PAIR_FROM_ENUM(LinkType::ZWAVE_R3),
                                                                 GET_PAIR_FROM_ENUM(LinkType::WATTSTOPPER_DLM),
                                                                 GET_PAIR_FROM_ENUM(LinkType::ISO_14443),
                                                                 GET_PAIR_FROM_ENUM(LinkType::RDS),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USB_DARWIN),
                                                                 GET_PAIR_FROM_ENUM(LinkType::SDLC),
                                                                 GET_PAIR_FROM_ENUM(LinkType::LORATAP),
                                                                 GET_PAIR_FROM_ENUM(LinkType::VSOCK),
                                                                 GET_PAIR_FROM_ENUM(LinkType::NORDIC_BLE),
                                                                 GET_PAIR_FROM_ENUM(LinkType::DOCSIS31_XRA31),
                                                                 GET_PAIR_FROM_ENUM(LinkType::ETHERNET_MPACKET),
                                                                 GET_PAIR_FROM_ENUM(LinkType::DISPLAYPORT_AUX),
                                                                 GET_PAIR_FROM_ENUM(LinkType::LINUX_SLL2),
                                                                 GET_PAIR_FROM_ENUM(LinkType::OPENVIZSLA),
                                                                 GET_PAIR_FROM_ENUM(LinkType::EBHSCR),
                                                                 GET_PAIR_FROM_ENUM(LinkType::VPP_DISPATCH),
                                                                 GET_PAIR_FROM_ENUM(LinkType::DSA_TAG_BRCM),
                                                                 GET_PAIR_FROM_ENUM(LinkType::DSA_TAG_BRCM_PREPEND),
                                                                 GET_PAIR_FROM_ENUM(LinkType::IEEE802_15_4_TAP),
                                                                 GET_PAIR_FROM_ENUM(LinkType::DSA_TAG_DSA),
                                                                 GET_PAIR_FROM_ENUM(LinkType::DSA_TAG_EDSA),
                                                                 GET_PAIR_FROM_ENUM(LinkType::ELEE),
                                                                 GET_PAIR_FROM_ENUM(LinkType::Z_WAVE_SERIAL),
                                                                 GET_PAIR_FROM_ENUM(LinkType::USB_2_0),
                                                                 GET_PAIR_FROM_ENUM(LinkType::ATSC_ALP),
                                                                 GET_PAIR_FROM_ENUM(LinkType::ETW),
                                                                 GET_PAIR_FROM_ENUM(LinkType::ZBOSS_NCP) };

// clang-format off
static const std::map<LinkType, std::string_view> LinkTypeDescriptions
{
    { LinkType::NULL_                        , "BSD loopback encapsulation; the link layer header is a 4-byte field, in host byte order, containing a value of 2 for IPv4 packets, a value of either 24, 28, or 30 for IPv6 packets, a value of 7 for OSI packets, or a value of 23 for IPX packets. All of the IPv6 values correspond to IPv6 packets; code reading files should check for all of them. ote that ``host byte order'' is the byte order of the machine on that the packets are captured; if a live capture is being done, ``host byte order'' is the byte order of the machine capturing the packets, but if a ``savefile'' is being read, the byte order is not necessarily that of the machine reading the capture file." },
    { LinkType::ETHERNET                     , "IEEE 802.3 Ethernet (10Mb, 100Mb, 1000Mb, and up); the 10MB in the DLT_ name is historical." },
    { LinkType::AX25                         , "AX.25 packet, with nothing preceding it." },
    { LinkType::IEEE802_5                    , "IEEE 802.5 Token Ring; the IEEE802, without _5, in the DLT_ name is historical." },
    { LinkType::ARCNET_BSD                   , "ARCNET Data Packets, as described by the ARCNET Trade Association standard ATA 878.1-1999, but without the Starting Delimiter, Information Length, or Frame Check Sequence fields, and with only the first ISU of the Destination Identifier. For most packet types, ARCNET Trade Association draft standard ATA 878.2 is also used. See also RFC 1051 and RFC 1201; for RFC 1051 frames, ATA 878.2 is not used." },
    { LinkType::SLIP                         , "SLIP, encapsulated with a LINKTYPE_SLIP header." },
    { LinkType::PPP                          , "PPP, as per RFC 1661 and RFC 1662; if the first 2 bytes are 0xff and 0x03, it's PPP in HDLC-like framing, with the PPP header following those two bytes, otherwise it's PPP without framing, and the packet begins with the PPP header. The data in the frame is not octet-stuffed or bit-stuffed." },
    { LinkType::FDDI                         , "FDDI, as specified by ANSI INCITS 239-1994." },
    { LinkType::PPP_HDLC                     , "PPP in HDLC-like framing, as per RFC 1662, or Cisco PPP with HDLC framing, as per section 4.3.1 of RFC 1547; the first byte will be 0xFF for PPP in HDLC-like framing, and will be 0x0F or 0x8F for Cisco PPP with HDLC framing. The data in the frame is not octet-stuffed or bit-stuffed." },
    { LinkType::PPP_ETHER                    , "PPPoE; the packet begins with a PPPoE header, as per RFC 2516." },
    { LinkType::ATM_RFC1483                  , "RFC 1483 LLC/SNAP-encapsulated ATM; the packet begins with an ISO 8802-2 (formerly known as IEEE 802.2) LLC header." },
    { LinkType::RAW                          , "Raw IP; the packet begins with an IPv4 or IPv6 header, with the version field of the header indicating whether it's an IPv4 or IPv6 header." },
    { LinkType::C_HDLC                       , "Cisco PPP with HDLC framing, as per section 4.3.1 of RFC 1547." },
    { LinkType::IEEE802_11                   , "IEEE 802.11 wireless LAN." },
    { LinkType::FRELAY                       , "Frame Relay LAPF frames, beginning with a ITU-T Recommendation Q.922 LAPF header starting with the address field, and without an FCS at the end of the frame." },
    { LinkType::LOOP                         , "OpenBSD loopback encapsulation; the link-layer header is a 4-byte field, in network byte order, containing a value of 2 for IPv4 packets, a value of either 24, 28, or 30 for IPv6 packets, a value of 7 for OSI packets, or a value of 23 for IPX packets. All of the IPv6 values correspond to IPv6 packets; code reading files should check for all of them." },
    { LinkType::LINUX_SLL                    , "Linux \"cooked\" capture encapsulation." },
    { LinkType::LTALK                        , "Apple LocalTalk; the packet begins with an AppleTalk LocalTalk Link Access Protocol header, as described in chapter 1 of Inside AppleTalk, Second Edition." },
    { LinkType::PFLOG                        , "OpenBSD pflog; the link-layer header contains a struct pfloghdr structure, as defined by the host on that the file was saved. (This differs from operating system to operating system and release to release; there is nothing in the file to indicate what the layout of that structure is.)" },
    { LinkType::IEEE802_11_PRISM             , "Prism monitor mode information followed by an 802.11 header." },
    { LinkType::IP_OVER_FC                   , "RFC 2625 IP-over-Fibre Channel, with the link-layer header being the Network_Header as described in that RFC." },
    { LinkType::SUNATM                       , "ATM traffic, encapsulated as per the scheme used by SunATM devices." },
    { LinkType::IEEE802_11_RADIOTAP          , "Radiotap link-layer information followed by an 802.11 header." },
    { LinkType::ARCNET_LINUX                 , "ARCNET Data Packets, as described by the ARCNET Trade Association standard ATA 878.1-1999, but without the Starting Delimiter, Information Length, or Frame Check Sequence fields, with only the first ISU of the Destination Identifier, and with an extra two-ISU offset field following the Destination Identifier. For most packet types, ARCNET Trade Association draft standard ATA 878.2 is also used; however, no exception frames are supplied, and reassembled frames, rather than fragments, are supplied. See also RFC 1051 and RFC 1201; for RFC 1051 frames, ATA 878.2 is not used." },
    { LinkType::APPLE_IP_OVER_IEEE1394       , "Apple IP-over-IEEE 1394 cooked header." },
    { LinkType::MTP2_WITH_PHDR               , "Signaling System 7 Message Transfer Part Level 2, as specified by ITU-T Recommendation Q.703, preceded by a pseudo-header." },
    { LinkType::MTP2                         , "Signaling System 7 Message Transfer Part Level 2, as specified by ITU-T Recommendation Q.703." },
    { LinkType::MTP3                         , "Signaling System 7 Message Transfer Part Level 3, as specified by ITU-T Recommendation Q.704, with no MTP2 header preceding the MTP3 packet." },
    { LinkType::SCCP                         , "Signaling System 7 Signalling Connection Control Part, as specified by ITU-T Recommendation Q.711, ITU-T Recommendation Q.712, ITU-T Recommendation Q.713, and ITU-T Recommendation Q.714, with no MTP3 or MTP2 headers preceding the SCCP packet." },
    { LinkType::DOCSIS                       , "DOCSIS MAC frames, as described by the DOCSIS 3.1 MAC and Upper Layer Protocols Interface Specification or earlier specifications for MAC frames." },
    { LinkType::LINUX_IRDA                   , "Linux-IrDA packets, with a LINKTYPE_LINUX_IRDA header, with the payload for IrDA frames beginning with by the IrLAP header as defined by IrDA Data Specifications, including the IrDA Link Access Protocol specification." },
    { LinkType::USER0                        , "Reserved for private use." },
    { LinkType::USER1                        , "Reserved for private use." },
    { LinkType::USER2                        , "Reserved for private use." },
    { LinkType::USER3                        , "Reserved for private use." },
    { LinkType::USER4                        , "Reserved for private use." },
    { LinkType::USER5                        , "Reserved for private use." },
    { LinkType::USER6                        , "Reserved for private use." },
    { LinkType::USER7                        , "Reserved for private use." },
    { LinkType::USER8                        , "Reserved for private use." },
    { LinkType::USER10                       , "Reserved for private use." },
    { LinkType::USER11                       , "Reserved for private use." },
    { LinkType::USER12                       , "Reserved for private use." },
    { LinkType::USER13                       , "Reserved for private use." },
    { LinkType::USER14                       , "Reserved for private use." },
    { LinkType::USER15                       , "Reserved for private use." },
    { LinkType::USER16                       , "Reserved for private use." },
    { LinkType::IEEE802_11_AVS               , "AVS monitor mode information followed by an 802.11 header." },
    { LinkType::BACNET_MS_TP                 , "BACnet MS/TP frames, as specified by section 9.3 MS/TP Frame Format of ANSI/ASHRAE Standard 135, BACnet� - A Data Communication Protocol for Building Automation and Control Networks, including the preamble and, if present, the Data CRC." },
    { LinkType::PPP_PPPD                     , "PPP in HDLC-like encapsulation, like LINKTYPE_PPP_HDLC, but with the 0xff address byte replaced by a direction indication�0x00 for incoming and 0x01 for outgoing." },
    { LinkType::GPRS_LLC                     , "General Packet Radio Service Logical Link Control, as defined by 3GPP TS 04.64." },
    { LinkType::GPF_T                        , "Transparent-mapped generic framing procedure, as specified by ITU-T Recommendation G.7041/Y.1303." },
    { LinkType::GPF_F                        , "Frame-mapped generic framing procedure, as specified by ITU-T Recommendation G.7041/Y.1303." },
    { LinkType::LINUX_LAPD                   , "Link Access Procedures on the D Channel (LAPD) frames, as specified by ITU-T Recommendation Q.920 and ITU-T Recommendation Q.921, captured via vISDN, with a LINKTYPE_LINUX_LAPD header, followed by the Q.921 frame, starting with the address field." },
    { LinkType::MFR                          , "Multi-Link Frame Relay frames, beginning with an FRF.12 Interface fragmentation format fragmentation header." },
    { LinkType::BLUETOOTH_HCI_H4             , "Bluetooth HCI UART transport layer; the frame contains an HCI packet indicator byte, as specified by the UART Transport Layer portion of the most recent Bluetooth Core specification, followed by an HCI packet of the specified packet type, as specified by the Host Controller Interface Functional Specification portion of the most recent Bluetooth Core Specification." },
    { LinkType::USB_LINUX                    , "USB packets, beginning with a Linux USB header, as specified by the struct usbmon_packet in the Documentation/usb/usbmon.txt file in the Linux source tree. Only the first 48 bytes of that header are present. All fields in the header are in host byte order. When performing a live capture, the host byte order is the byte order of the machine on that the packets are captured. When reading a pcap file, the byte order is the byte order for the file, as specified by the file's magic number; when reading a pcapng file, the byte order is the byte order for the section of the pcapng file, as " },
    { LinkType::PPI                          , "Per-Packet Information information, as specified by the Per-Packet Information Header Specification, followed by a packet with the LINKTYPE_ value specified by the pph_dlt field of that header." },
    { LinkType::IEEE802_15_4_WITHFCS         , "IEEE 802.15.4 Low-Rate Wireless Networks, with each packet having the FCS at the end of the frame." },
    { LinkType::SITA                         , "Various link-layer types, with a pseudo-header, for SITA." },
    { LinkType::ERF                          , "Various link-layer types, with a pseudo-header, for Endace DAG cards; encapsulates Endace ERF records." },
    { LinkType::BLUETOOTH_HCI_H4_WITH_PHDR   , "Bluetooth HCI UART transport layer; the frame contains a 4-byte direction field, in network byte order (big-endian), the low-order bit of which is set if the frame was sent from the host to the controller and clear if the frame was received by the host from the controller, followed by an HCI packet indicator byte, as specified by the UART Transport Layer portion of the most recent Bluetooth Core specification, followed by an HCI packet of the specified packet type, as specified by the Host Controller Interface Functional Specification portion of the most recent Bluetooth Core Specifi" },
    { LinkType::AX25_KISS                    , "AX.25 packet, with a 1-byte KISS header containing a type indicator." },
    { LinkType::LAPD                         , "Link Access Procedures on the D Channel (LAPD) frames, as specified by ITU-T Recommendation Q.920 and ITU-T Recommendation Q.921, starting with the address field, with no pseudo-header." },
    { LinkType::PPP_WITH_DIR                 , "PPP, as per RFC 1661 and RFC 1662, preceded with a one-byte pseudo-header with a zero value meaning \"received by this host\" and a non-zero value meaning \"sent by this host\"; if the first 2 bytes are 0xff and 0x03, it's PPP in HDLC-like framing, with the PPP header following those two bytes, otherwise it's PPP without framing, and the packet begins with the PPP header. The data in the frame is not octet-stuffed or bit-stuffed." },
    { LinkType::C_HDLC_WITH_DIR              , "Cisco PPP with HDLC framing, as per section 4.3.1 of RFC 1547, preceded with a one-byte pseudo-header with a zero value meaning \"received by this host\" and a non-zero value meaning \"sent by this host\"." },
    { LinkType::FRELAY_WITH_DIR              , "Frame Relay LAPF frames, beginning with a one-byte pseudo-header with a zero value meaning \"received by this host\" (DCE->DTE) and a non-zero value meaning \"sent by this host\" (DTE->DCE), followed by an ITU-T Recommendation Q.922 LAPF header starting with the address field, and without an FCS at the end of the frame." },
    { LinkType::LAPB_WITH_DIR                , "Link Access Procedure, Balanced (LAPB), as specified by ITU-T Recommendation X.25, preceded with a one-byte pseudo-header with a zero value meaning \"received by this host\" (DCE->DTE) and a non-zero value meaning \"sent by this host\" (DTE->DCE)." },
    { LinkType::IPMB_LINUX                   , "IPMB over an I2C circuit, with a Linux-specific pseudo-header." },
    { LinkType::FLEXRAY                      , "FlexRay automotive bus frames or symbols, preceded by a pseudo-header." },
    { LinkType::LIN                          , "Local Interconnect Network (LIN) automotive bus, preceded by a pseudo-header." },
    { LinkType::IEEE802_15_4_NONASK_PHY      , "IEEE 802.15.4 Low-Rate Wireless Networks, with each packet having the FCS at the end of the frame, and with the PHY-level data for the O-QPSK, BPSK, GFSK, MSK, and RCC DSS BPSK PHYs (4 octets of 0 as preamble, one octet of SFD, one octet of frame length + reserved bit) preceding the MAC-layer data (starting with the frame control field)." },
    { LinkType::USB_LINUX_MMAPPED            , "USB packets, beginning with a Linux USB header, as specified by the struct usbmon_packet in the Documentation/usb/usbmon.txt file in the Linux source tree. All 64 bytes of the header are present. All fields in the header are in host byte order. When performing a live capture, the host byte order is the byte order of the machine on that the packets are captured. When reading a pcap file, the byte order is the byte order for the file, as specified by the file's magic number; when reading a pcapng file, the byte order is the byte order for the section of the pcapng file, as specified by" },
    { LinkType::FC_2                         , "Fibre Channel FC-2 frames, beginning with a Frame_Header." },
    { LinkType::FC_2_WITH_FRAME_DELIMS       , "Fibre Channel FC-2 frames, beginning an encoding of the SOF, followed by a Frame_Header, and ending with an encoding of the SOF. The encodings represent the frame delimiters as 4-byte sequences representing the corresponding ordered sets, with K28.5 represented as 0xBC, and the D symbols as the corresponding byte values; for example, SOFi2, which is K28.5 - D21.5 - D1.2 - D21.2, is represented as 0xBC 0xB5 0x55 0x55." },
    { LinkType::IPNET                        , "Solaris ipnet pseudo-header, followed by an IPv4 or IPv6 datagram." },
    { LinkType::CAN_SOCKETCAN                , "CAN (Controller Area Network) frames, with a pseudo-header followed by the frame payload." },
    { LinkType::IPV4                         , "Raw IPv4; the packet begins with an IPv4 header." },
    { LinkType::IPV6                         , "Raw IPv6; the packet begins with an IPv6 header." },
    { LinkType::IEEE802_15_4_NOFCS           , "IEEE 802.15.4 Low-Rate Wireless Network, without the FCS at the end of the frame." },
    { LinkType::DBUS                         , "Raw D-Bus messages, starting with the endianness flag, followed by the message type, etc., but without the authentication handshake before the message sequence." },
    { LinkType::DVB_CI                       , "DVB-CI (DVB Common Interface for communication between a PC Card module and a DVB receiver), with the message format specified by the PCAP format for DVB-CI specification." },
    { LinkType::MUX27010                     , "Variant of 3GPP TS 27.010 multiplexing protocol (similar to, but not the same as, 27.010)." },
    { LinkType::STANAG_5066_D_PDU            , "D_PDUs as described by NATO standard STANAG 5066, starting with the synchronization sequence, and including both header and data CRCs. The current version of STANAG 5066 is backwards-compatible with the 1.0.2 version, although newer versions are classified." },
    { LinkType::NFLOG                        , "Linux netlink NETLINK NFLOG socket log messages." },
    { LinkType::NETANALYZER                  , "Pseudo-header for Hilscher Gesellschaft f�r Systemautomation mbH netANALYZER devices, followed by an Ethernet frame, beginning with the MAC header and ending with the FCS." },
    { LinkType::NETANALYZER_TRANSPARENT      , "Pseudo-header for Hilscher Gesellschaft f�r Systemautomation mbH netANALYZER devices, followed by an Ethernet frame, beginning with the preamble, SFD, and MAC header, and ending with the FCS." },
    { LinkType::IPOIB                        , "IP-over-InfiniBand, as specified by RFC 4391 section 6." },
    { LinkType::MPEG_2_TS                    , "MPEG-2 Transport Stream transport packets, as specified by ISO 13818-1/ITU-T Recommendation H.222.0 (see table 2-2 of section 2.4.3.2 \"Transport Stream packet layer\")." },
    { LinkType::NG40                         , "Pseudo-header for ng4T GmbH's UMTS Iub/Iur-over-ATM and Iub/Iur-over-IP format as used by their ng40 protocol tester, followed by frames for the Frame Protocol as specified by 3GPP TS 25.427 for dedicated channels and 3GPP TS 25.435 for common/shared channels in the case of ATM AAL2 or UDP traffic, by SSCOP packets as specified by ITU-T Recommendation Q.2110 for ATM AAL5 traffic, and by NBAP packets for SCTP traffic." },
    { LinkType::NFC_LLCP                     , "Pseudo-header for NFC LLCP packet captures, followed by frame data for the LLCP Protocol as specified by NFCForum-TS-LLCP_1.1." },
    { LinkType::INFINIBAND                   , "Raw InfiniBand frames, starting with the Local Routing Header, as specified in Chapter 5 \"Data packet format\" of InfiniBand� Architectural Specification Release 1.2.1 Volume 1 - General Specifications." },
    { LinkType::SCTP                         , "SCTP packets, as defined by RFC 4960, with no lower-level protocols such as IPv4 or IPv6." },
    { LinkType::USBPCAP                      , "USB packets, beginning with a USBPcap header." },
    { LinkType::RTAC_SERIAL                  , "Serial-line packet header for the Schweitzer Engineering Laboratories \"RTAC\" product, followed by a payload for one of a number of industrial control protocols." },
    { LinkType::BLUETOOTH_LE_LL              , "Bluetooth Low Energy air interface Link Layer packets, in the format described in section 2.1 \"PACKET FORMAT\" of volume 6 of the Bluetooth Specification Version 4.0 (see PDF page 2200), but without the Preamble." },
    { LinkType::NETLINK                      , "Linux Netlink capture encapsulation." },
    { LinkType::BLUETOOTH_LINUX_MONITOR      , "Bluetooth Linux Monitor encapsulation of traffic for the BlueZ stack." },
    { LinkType::BLUETOOTH_BREDR_BB           , "Bluetooth Basic Rate and Enhanced Data Rate baseband packets." },
    { LinkType::BLUETOOTH_LE_LL_WITH_PHDR    , "Bluetooth Low Energy link-layer packets." },
    { LinkType::PROFIBUS_DL                  , "PROFIBUS data link layer packets, as specified by IEC standard 61158-4-3, beginning with the start delimiter, ending with the end delimiter, and including all octets between them." },
    { LinkType::PKTAP                        , "Apple PKTAP capture encapsulation." },
    { LinkType::EPON                         , "Ethernet-over-passive-optical-network packets, starting with the last 6 octets of the modified preamble as specified by 65.1.3.2 \"Transmit\" in Clause 65 of Section 5 of IEEE 802.3, followed immediately by an Ethernet frame." },
    { LinkType::IPMI_HPM_2                   , "IPMI trace packets, as specified by Table 3-20 \"Trace Data Block Format\" in the PICMG HPM.2 specification. The time stamps for packets in this format must match the time stamps in the Trace Data Blocks." },
    { LinkType::ZWAVE_R1_R2                  , "Z-Wave RF profile R1 and R2 packets, as specified by ITU-T Recommendation G.9959, with some MAC layer fields moved." },
    { LinkType::ZWAVE_R3                     , "Z-Wave RF profile R3 packets, as specified by ITU-T Recommendation G.9959, with some MAC layer fields moved." },
    { LinkType::WATTSTOPPER_DLM              , "Formats for WattStopper Digital Lighting Management (DLM) and Legrand Nitoo Open protocol common packet structure captures." },
    { LinkType::ISO_14443                    , "Messages between ISO 14443 contactless smartcards (Proximity Integrated Circuit Card, PICC) and card readers (Proximity Coupling Device, PCD), with the message format specified by the PCAP format for ISO14443 specification." },
    { LinkType::RDS                          , "Radio data system (RDS) groups, as per IEC 62106, encapsulated in this form." },
    { LinkType::USB_DARWIN                   , "USB packets, beginning with a Darwin (macOS, etc.) USB header." },
    { LinkType::SDLC                         , "SDLC packets, as specified by Chapter 1, \"DLC Links\", section \"Synchronous Data Link Control(SDLC)\" of Systems Network Architecture Formats, GA27-3136-20, without the flag fields, zero-bit insertion, or Frame Check Sequence field, containing SNA path information units (PIUs) as the payload." },
    { LinkType::LORATAP                      , "LoRaTap pseudo-header, followed by the payload, which is typically the PHYPayload from the LoRaWan specification." },
    { LinkType::VSOCK                        , "Protocol for communication between host and guest machines in VMware and KVM hypervisors." },
    { LinkType::NORDIC_BLE                   , "Messages to and from a Nordic Semiconductor nRF Sniffer for Bluetooth LE packets, beginning with a pseudo-header." },
    { LinkType::DOCSIS31_XRA31               , "DOCSIS packets and bursts, preceded by a pseudo-header giving metadata about the packet." },
    { LinkType::ETHERNET_MPACKET             , "mPackets, as specified by IEEE 802.3br Figure 99-4, starting with the preamble and always ending with a CRC field." },
    { LinkType::DISPLAYPORT_AUX              , "DisplayPort AUX channel monitoring data as specified by VESA DisplayPort (DP) Standard preceded by a pseudo-header." },
    { LinkType::LINUX_SLL2                   , "Linux \"cooked\" capture encapsulation v2." },
    { LinkType::OPENVIZSLA                   , "Openvizsla FPGA-based USB sniffer." },
    { LinkType::EBHSCR                       , "Elektrobit High Speed Capture and Replay (EBHSCR) format." },
    { LinkType::VPP_DISPATCH                 , "Records in traces from the http://fd.io VPP graph dispatch tracer, in the the graph dispatcher trace format." },
    { LinkType::DSA_TAG_BRCM                 , "Ethernet frames, with a switch tag inserted between the source address field and the type/length field in the Ethernet header." },
    { LinkType::DSA_TAG_BRCM_PREPEND         , "Ethernet frames, with a switch tag inserted before the destination address in the Ethernet header." },
    { LinkType::IEEE802_15_4_TAP             , "IEEE 802.15.4 Low-Rate Wireless Networks, with a pseudo-header containing TLVs with metadata preceding the 802.15.4 header." },
    { LinkType::DSA_TAG_DSA                  , "Ethernet frames, with a switch tag inserted between the source address field and the type/length field in the Ethernet header." },
    { LinkType::DSA_TAG_EDSA                 , "Ethernet frames, with a programmable Ethernet type switch tag inserted between the source address field and the type/length field in the Ethernet header." },
    { LinkType::ELEE                         , "Payload of lawful intercept packets using the ELEE protocol. The packet begins with the ELEE header; it does not include any transport-layer or lower-layer headers for protcols used to transport ELEE packets." },
    { LinkType::Z_WAVE_SERIAL                , "Serial frames transmitted between a host and a Z-Wave chip over an RS-232 or USB serial connection, as described in section 5 of the Z-Wave Serial API Host Application Programming Guide." },
    { LinkType::USB_2_0                      , "USB 2.0, 1.1, or 1.0 packet, beginning with a PID, as described by Chapter 8 \"Protocol Layer\" of the the Universal Serial Bus Specification Revision 2.0." },
    { LinkType::ATSC_ALP                     , "ATSC Link-Layer Protocol frames, as described in section 5 of the A/330 Link-Layer Protocol specification, found at the ATSC 3.0 standards page, beginning with a Base Header." },
    { LinkType::ETW                          , "Event Tracing for Windows messages, beginning with a pseudo-header." },
    { LinkType::ZBOSS_NCP                    , "Serial NCP (Network Co-Processor) protocol for Zigbee stack ZBOSS by DSR. ZBOSS NCP protocol, beginning with a header" }
};
// clang-format on

struct Header
{
    Magic magicNumber;   /* Used to detect the file format itself and the byte ordering. The writing application writes 0xa1b2c3d4 with it's
                            native byte ordering format into this field. The reading application will read either 0xa1b2c3d4 (identical) or
                            0xd4c3b2a1 (swapped). If the reading application reads the swapped 0xd4c3b2a1 value, it knows that all the
                            following fields will have to be swapped too. */
    uint16 versionMajor; /* The version number of this file format 2. */
    uint16 versionMinor; /* The version number of this file format 4. */
    int32 thiszone;   /* The correction time in seconds between GMT (UTC) and the local timezone of the following packet header timestamps.
                         Examples: If the timestamps are in GMT (UTC), thiszone is simply 0. If the timestamps are in Central European time
                         (Amsterdam, Berlin, �) which is GMT + 1:00, thiszone must be -3600. In practice, time stamps are always in GMT, so
                         thiszone is always 0. */
    uint32 sigfigs;   /* In theory, the accuracy of time stamps in the capture; in practice, all tools set it to 0. */
    uint32 snaplen;   /* Max length of captured packets, in octets. The "snapshot length" for the capture (typically 65535 or even more, but
                         might be limited by the user). */
    LinkType network; /* Link-layer header type, specifying the type of headers at the beginning of the packet. */
};

static_assert(sizeof(Header) == 24);

namespace NG
{
    enum class Magic : uint32
    {
        First  = 0xA1B2C3D4, // time stamps in Packet Records are in seconds and microseconds;
        Second = 0xA1B23C4D  // time stamps in Packet Records are in seconds and nanoseconds.
    };

    struct LinkType
    {
        uint8 : 8;
        uint8 : 8;
        uint8 : 8;
        uint8 : 4;
        uint8 f : 1;
        uint8 FCS : 3;
    };

    struct Header
    {
        Magic magicNumber; // These numbers can be used to distinguish sections that have been saved on little-endian machines from the ones
                           // saved on big-endian machines, and to heuristically identify pcap files.
        uint16 majorVersion; // The value for the current version of the format is 2. This value should change if the format changes in such
                             // a way that code that reads the new format could not read the old format (i.e., code to read both formats
                             // would have to check the version number and use different code paths for the two formats) and code that reads
                             // the old format could not read the new format.
        uint16 minorVersion; // The value is for the current version of the format is 4. This value should change if the format changes in
                             // such a way that code that reads the new format could read the old format without checking the version number
                             // but code that reads the old format could not read all files in the new format.
        uint32 reserved1;    // Not used - SHOULD be filled with 0 by pcap file writers, and MUST be ignored by pcap file readers.This value
                          // was documented by some older implementations as "gmt to local correction".Some older pcap file writers stored
                          // non - zero values in this field.
        uint32 reserved2; // Not used - SHOULD be filled with 0 by pcap file writers, and MUST be ignored by pcap file readers.This value
                          // was documented by some older implementations as "accuracy of timestamps".Some older pcap file writers stored
                          // non - zero values in this field.
        uint32 snapLen; // Maximum number of octets captured from each packet.The portion of each packet that exceeds this value will not be
                        // stored in the file.This value MUST NOT be zero; if no limit was specified, the value should be a number greater
                        // than or equal to the largest packet length in the file.
        LinkType linkType; // Defines, in the lower 28 bits, the link layer type of packets in the file.
    };

    static_assert(sizeof(Header) == 24);
} // namespace NG
} // namespace GView::Type::PCAP
