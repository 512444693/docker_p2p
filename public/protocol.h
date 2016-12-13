/*
* Copyright (c) 2008 ��������
* All rights reserved.
* 
* �ļ�����: protocol.h
* �ļ���ʶ:
* ժ Ҫ: ����p2p���ص�Э��
* ��ǰ�汾: 1.0
* �� ��: chen.qian.jiang
* ��ʼ����: 2008-03-16
* �������: 
* ����˵���� 
* �޸����� �汾�� �޸��� �޸�����
* -----------------------------------------------
* 2008/03/16 V1.0 ��ǭ�� ����
* 2008/03/18 V1.1 ���� ����peer���͵ĺ궨��; �޸�"���"���ֵ�Э��
*/

#ifndef _PROTOCOL__H
#define _PROTOCOL__H
#include <string>

#ifdef _WIN32
	#pragma warning(disable:4200)
#endif

#pragma pack(push, 1)

#define TCP_HTTP_ASCII_HEAD		 "GET /abcd HTTP/1.1\r\n"
#define TCP_HTTP_ASCII_HEAD_SIZE strlen(TCP_HTTP_ASCII_HEAD)

#define VOD_PROTOCOL_VER      0x0103
#define VOD_PRE_PROTOCOL_VER  0x0102
#define VOD_MINI_PROTOCOL_VER 0x0101

#define CRCCHECK_OFFSET       59
#define CRCCHECK_SIZE         20//(8+4+4+4)
#define NEW_CLIENT_VOD_PROTOCOL_VER		0x65

struct base_head
{
	int protocol_ver;		//Э��汾
	int seq;				//�����
	int command_len;		//�����
};

typedef struct request_head_t:public base_head
{
	short command_id;		//����id
}common_head_t;

struct response_head_t
{
	int protocol_ver;	   //Э��汾
	int seq;			       //�����
	int command_len;	   //�����
	short command_id;	   //����id
	char succ;			     //�Ƿ�ɹ�
};

enum
{
	PEER_TYPE_NP,
	PEER_TYPE_HVP = 2,
	PEER_TYPE_CVP,
	PEER_TYPE_MIF
};

#define 	CONNECT_DIRECT		    1	  //ֱ������
#define 	CONNECT_HOLE_REQUEST    2	  //������
#define 	CONNECT_INITINATIVE     3     //��������
#define 	CONNECT_PASSIVITY	    4	  //��������

struct peer_info
{
	std::string peer_id;
	unsigned int internal_ip;
	unsigned int protocal_ver;
	short tcp_port;
	short udp_port;
	int p2p_attribute;
	int peerpriority;
	int downscale;
	char peertype;
	char connecttype; 
	char connectpassivity;

	peer_info()
	{
		internal_ip = 0;
		tcp_port = 0;
		udp_port = 0;
		p2p_attribute = 0;
		peerpriority = 0;
		downscale = 0;
		peertype = 0;
		connecttype = 0;
		connectpassivity = 0;
	}

	void operator =(const peer_info &peerinfo) 
	{
		peer_id = peerinfo.peer_id;
		internal_ip = peerinfo.internal_ip;
		tcp_port = peerinfo.tcp_port;
		udp_port = peerinfo.udp_port;
		p2p_attribute = peerinfo.p2p_attribute;
		peerpriority = peerinfo.peerpriority;
		downscale = peerinfo.downscale;
		peertype = peerinfo.peertype;
		connectpassivity = peerinfo.connectpassivity;
		connecttype = peerinfo.connecttype;
	}

	bool operator==(const peer_info &item)
	{
		if (peer_id != item.peer_id)
		{
			return false;
		}

		if (tcp_port != item.tcp_port)
		{
			return false;
		}

		if (udp_port != item.udp_port)
		{
			return false;
		}
		
		return true;
	}

};

struct play_item 
{
	play_item(std::string cid, std::string name)
	{
		s_cid = cid;
		s_name = name;
	}
	std::string s_cid;
	std::string s_name;
};
// ��Ϣ�� add��
#define ON_RESULT_OK 0
#define ON_RESULT_FAILE 1


// P2pattribute����:
#define PEER_IN_NAT 1  // ����
#define PEER_NAT    2  // ֧�ִ�͸
#define PEER_IN_SAME_NAT 4// ͬһ������

///////////////////////////////////
//seed������Э��
#define SEED_LOGIN			1000
#define SEED_LOGIN_RES		1001
#define SEED_REPORT_RC		1002
#define SEED_REPORT_RC_RES	1003
#define SEED_INSERT_RC		1004
#define SEED_INSERT_RC_RES	1005
#define SEED_DELETE_RC		1006
#define SEED_DELETE_RC_RES	1007
#define SEED_GETPEER		1008
#define SEED_GETPEER_RES	1009
#define	SEED_INVALID_PEER	1010

//online������Э��
#define ONLINE_PING			2000
#define ONLINE_PING_RES		2001
#define ONLINE_LOGOUT		2002
#define ONLINE_MONITOR		2100
#define ONLINE_MONITORRES	2101

//online��seed����������Э��
#define SYN_ONLINE			3000
#define SYN_LOGOUT			3002
#define SYN_ONTIME			3004
#define SYN_AFFIRM			3006
#define SYN_AFFIRM_RES		3007
#define SYN_HANDSHAKE		3008

//pcserver������Э��
#define PC_REQUEST_NEIGHBOR		5000
#define PC_REQUEST_NEIGHBOR_RES	5001
#define PC_REPORT_NEIGHBOR		5002
#define PC_REPORT_NEIGHBOR_RES	5003
#define PC_INQUIRE_NEIGHBOR		5004
#define PC_INQUIRE_NEIGHBOR_RES 5005
#define PC_BROADCAST_MSG		5006
#define PC_REQUEST_PUBLICKEY		5008
#define PC_REQUEST_PUBLICKEY_RES	5009
#define PC_BROADCAST_CTL_MSG		5010
#define PC_BROADCAST_CTL_MSG_RES	5011

//NetBroadcast p2p
#define NB_P2P_PING				5100				
#define NB_P2P_PING_RES			5101
#define NB_P2P_BROADCAST_MSG    5102

//Message Id
#define CONNECT_SERVER_COMMON 2000
#define ONLINE_SYN	2001		//wangtiefeng : 2009-01-10
#define CACHE_GET_DATA 12000
#define CACHE_GET_DATA_RES 12001
#define CACHE_INTEREST 12002
#define CACHE_INTEREST_RES 12003

//���Ϻ�
#define PEER_PRE_HANDSHAKE	3000
#define PEER_PRE_HANDSHAKE_RES 3001


/***************************************/
//������
#define E_OK 		    100
#define E_CLIENTID      101
#define E_CLIENTID_LEN  102
#define E_UDPPORT       103
#define E_UDPPORT_LEN   104
#define E_DNSLIST_LEN   105
#define E_ROUTERLIST_LEN 106
#define E_REPORTPOS      107
#define E_REPORTPOS_LEN  108
#define E_GETREPORTPARENT 109
#define E_BITMAP_NUM     110
#define E_BITMAP_LEN     111
#define E_CHID 		112
#define E_CHID_LEN      113
#define E_BLKSZIE 	114
#define E_PEER 		115 
#define E_NOCIS 	116
#define E_PWD 		117
#define E_CISID 	118
#define E_VERSION 	119
#define E_VPEERID 	120
#define E_CHN 		121
#define E_NOPEER 	122
#define E_SEEK_HEARTBEAT_PARENT 123
#define E_UNDEFINE      124
#define E_INCOMPLETE_INFO 125
#define E_FATAL         126
#define E_FEC_MISSED     127
#define E_DNSINDEX_LEN   128
#define E_DNSNUM_LEN     129
#define E_STATE_LEN      130
#define E_PEERLIST_LEN   131
#define E_ROUTERINDEX_LEN 132
#define E_SYSTEM_BUSY	  133
#define E_FECPACKETHEAD   134
#define E_FECPACKET_LEN   135
#define E_CHANNELNUM      136
#define E_NOCHNFILE 		121


//peer����
#define PEERTYPE_NP 	0 //normal peer (nat peer)
#define PEERTYPE_VP 	2 //virtual peer
#define PEERTYPE_HTTP 	3 //http peer


//********** index 30 - 39************
//use tcp
#define c_s_index_peerlogin 			30 // peer ��¼��index 
	#define c_s_index_peerlogin_clientid 	0 //8 byte
	#define c_s_index_peerlogin_dnsip 		1 //�䳤 
	#define c_s_index_peerlogin_routerip 	2 //�䳤

#define s_c_index_peerlogin 					31 // peer��¼��Ӧ 
	#define s_c_index_peerlogin_clientid 		0 //8byte
	#define s_c_index_peerlogin_dns_index 		1 //�䳤
	#define s_c_index_peerlogin_router_index    2 //�䳤
	#define s_c_index_peerlogin_publicip 		3 //4 bytes
	#define s_c_index_peerlogin_status 			4 //4 bytes
	#define s_c_index_peerlogin_vpeer_regionno	5 //4 bytes


//************ cis 60 - 79 **************
//use tcp
#define c_s_cis_getclientid 				68 //optional
	#define c_s_cis_getclientid_clientid		0 // 8byte 

#define s_c_cis_getclientid 				61 //optional
	#define s_c_cis_getclientid_clientid 		0 // 8byte
	#define s_c_cis_getclientid_publicip 		1 // 4byte
	#define s_c_cis_getclientid_status          2 // 4byte 

//use tcp
#define c_s_cis_getheartbeatparent 			62   //���ڲ����룬ֻnew����������
	#define c_s_cis_getheartbeatparent_clientid     0 // 8byte  // ��ʼnew���� 
   	#define c_s_s_cis_getheartbeatparent_port       1 // 2byte 
	#define c_s_cis_getheartbeatparent_dns_index 	2 // �䳤 
	#define c_s_cis_getheartbeatparent_router_index	3 // �䳤 
	#define c_s_cis_getheartbeatparent_posindex 	4 //4byte��Ϊ-1��ʾ��һ��ȡ


#define s_c_cis_getheartbeatparent 			63
	#define s_c_cis_getheartbeatparent_peerinfo 	0 //����׵���Ϣ
	#define s_c_cis_getheartbeatparent_posindex 	1 //4 bytes������λ��ֵ  // ������ 
	#define s_c_cis_getheartbeatparent_len 			2 //2 bytes��λͼ����
	#define s_c_cis_getheartbeatparent_layer		3 //1 byte������
	#define s_c_cis_getheartbeatparent_status 		4 // 4byte

#define c_s_cis_heartbeat 			        64    //�������Ƶ���µ�dns��·�ɱ�
	#define c_s_cis_heartbeat_clientid 	        0
	#define c_s_cis_heartbeat_bitmap_num        1 // 2byte
	#define c_s_cis_heartbeat_bitmap 			2 // �䳤 
	#define c_s_cis_heartbeat_posindex			3 // 4 bytes������λ��ֵ
	#define c_s_cis_heartbeat_channelid         4 // �䳤,��sizeof��report_t��*��bitmap��Ψһ��λ�ĸ������� 
	#define c_s_cis_heartbeat_status_num		5 // Ϊͳ��NP ������������  4 byte chnid + 4 byte Watch_NP_num + 4 bytes Share_NP_num ... 
	#define c_s_cis_heartbeat_np_num			6 // 4byte 


#define s_c_cis_heartbeat				65  
	#define s_c_cis_heartbeat_clientid		0
	#define s_c_cis_heartbeat_status		1   

#define c_s_heartbeat_handshake					66//��������
	#define c_s_heartbeat_handshake_clientid	0
	#define c_s_heartbeat_handshake_posindex	1	// 4 bytes������λ��ֵ
	#define c_s_heartbeat_handshake_layer		2	//1 byte

#define s_c_heartbeat_handshake					67
	#define s_c_heartbeat_handshake_clientid	0
	#define s_c_heartbeat_handshake_status		1	// 4byte

struct report_t
{
	short m_nChannelNum;
	char * m_pChannel;
};

struct reportnp_t
{
	int m_iChannelId;
	int m_iWatchNpNum;
	int m_iShareNpNum;
};


#define c_s_cis_getpeer 			66 ///peer��¼cis 
    #define c_s_cis_getpeer_chnid 			0 // 4byte
	#define c_s_cis_getpeer_clientid 		1 // 8byte
	#define c_s_cis_getpeer_num 			2 // 2bytes,Ҫ�󷵻ص�peer�������� 
	#define c_s_cis_getpeer_dns_index 		3 // �䳤 
	#define c_s_cis_getpeer_router_index 	4 // �䳤 
	#define c_s_cis_getpeer_posindex        5
	#define c_s_cis_getpeer_vpeer_regionno	6 // 4bytes 

#define s_c_cis_getpeer 			67 //peer��¼��Ӧ
    #define s_c_cis_getpeer_chnid			0 // 4byte
	#define s_c_cis_getpeer_clientid 		1 // 8byte
	#define s_c_cis_getpeer_num 			2 // 2bytes,Ҫ�󷵻ص�peer�������� 
	#define s_c_cis_getpeer_peerlist 	    3 // �Ƕ�����������struct peerlist_t  
	#define s_c_cis_getpeer_clientlimen     4 //2byte
	#define s_c_cis_getpeer_status 			5 // 4byte

struct peerlist_t
{
	unsigned long long clientid;
	unsigned int publicip;
	short port;
	unsigned char type; // PEERTYPE_NP,PEERTYPE_VP  
};

//////////////////////////////////////////////////////////////////////////

//������
#define c_s_cis_vpeerlogin 			70	//vpeer��¼��cis
	#define c_s_cis_vpeerlogin_id 			0 // 8�ֽ��ַ��� 
	#define c_s_cis_vpeerlogin_pwd 			1 // 8�ֽ��ַ���  
	#define c_s_cis_vpeerlogin_chnid 		2 // 4byte chnid + 4byte chnid... 
	#define c_s_cis_vpeerlogin_ifhotvpeer	3 //1 byte ��ʾvpeer�������Ƿ�Ϊ��vp����vp,1:��0:��


#define s_c_cis_vpeerlogin 			71 //vpeer��¼��Ӧ
	#define s_c_cis_vpeerlogin_id 		0 // �Ƕ��� 
	#define s_c_cis_vpeerlogin_status 	1 // 4byte 

#define c_s_cis_vpeerping 			72 //vpeer��cis��ping
	#define c_s_cis_vpeerping_id 		0 // �Ƕ��� 
	#define c_s_cis_vpeerping_add_chnid 	1 // 4byte chnid + 4byte chnid... 
	#define c_s_cis_vpeerping_del_chnid     2 // 4byte chnid + 4byte chnid... 
	#define c_s_cis_vpeerping_status_num	3 // Ϊͳ��NP ������������  4 byte chnid + 4 byte Watch_NP_num + 4 bytes Share_NP_num ... 
	#define c_s_cis_vpeerping_getdata_num	4
	#define c_s_cis_vpeerping_num 			5 // Ϊ���ؾ���������������� 4byte 
	#define c_s_cis_vpeerping_ifhotvpeer    6
	#define c_s_cis_vpeerping_numofchn		7 //4byteƵ����+4byte����...�䳤

#define s_c_cis_vpeerping 			73  //vpeer��ping��Ӧ
	#define s_c_cis_vpeerping_id 		0 // �Ƕ���
	#define s_c_cis_vpeerping_status 	1 // 4byte  


//use tcp
#define c_s_cis_getmorepeer_by_dns                 74
	#define c_s_cis_getmorepeer_by_dns_id				0
	#define c_s_cis_getmorepeer_by_dns_chnid			1
	#define c_s_cis_getmorepeer_by_dns_index			2
	#define c_s_cis_getmorepeer_by_dns_num				3

#define s_c_cis_getmorepeer_by_dns                 75
  #define s_c_cis_getmorepeer_by_dns_id					0
  #define s_c_cis_getmorepeer_by_dns_chnid				1
  #define s_c_cis_getmorepeer_by_dns_dns_index          2
  #define s_c_cis_getmorepeer_by_dns_peerlist           3  
  #define s_c_cis_getmorepeer_by_dns_state              4

#define c_s_cis_getmorepeer_by_router              76
  #define c_s_cis_getmorepeer_by_router_id				0
  #define c_s_cis_getmorepeer_by_router_chnid           1
  #define c_s_cis_getmorepeer_by_router_index           2
  #define c_s_cis_getmorepeer_by_router_num             3
  
#define s_c_cis_getmorepeer_by_router              77
  #define s_c_cis_getmorepeer_by_route_id				0
  #define s_c_cis_getmorepeer_by_route_chnid            1
  #define s_c_cis_getmorepeer_by_route_dns_index        2
  #define s_c_cis_getmorepeer_by_route_peerlist         3 
  #define s_c_cis_getmorepeer_by_router_state           4
  
#define c_s_cis_cisping					78
  #define c_s_cis_cisping_id                  0

#define s_c_cis_cisping					79
  #define s_c_cis_cisping_id			      0
  #define s_c_cis_cisping_state               1



// peerinfo 
struct peer_t						// peer_info 
{
	unsigned long long	clientid;		// �ͻ���ID	 8byte 
	unsigned int 		natip;			// ����ip 
	unsigned short 		natport;		// ����port 
	unsigned char		peertype;		// peer����: PEERTYPE_NP,PEERTYPE_VP ��PEERTYPE_SP  
};

struct seekable_info_table_t {
	unsigned int len;
	unsigned int * table;
};

struct general_info_t
{
	char nType; //0-wmv; 1-rmvb,...
	unsigned int nPlayTime; //in seconds;
	unsigned char nVNameLen;
	unsigned int nFileLen;
	char szVName[0];
};

//peerinfo 
struct peer_info_t					// peer_info 
{
	std::string         clientid;		// �ͻ���ID	 8byte  
	unsigned int		publicip;		// ����IP	 4byte  
	unsigned short		publicport;		// �����˿�	 2byte 
	unsigned int 		natip;
	unsigned short 		natport;
	unsigned char		peertype;		// peer����	 1byte   
};

// peer ��Peer ֮���ͨѸЭ����Ϣ�ţ�40 - 46
#define	c_s_get_media_info			    40 // 2byte����ý����Ϣ��Ϣ
#define	c_s_get_media_info_channelid	    // string
#define	c_s_get_media_info_clientid		    // string 
         
#define	s_c_get_media_info			    41// 2byteý����Ϣ������Ϣ
#define	s_c_get_media_info_channelid	// string
#define	s_c_get_media_info_clientid	    // string
#define s_c_get_media_info_filesize	    // 4byte

#define c_c_peer_peerfilemap 		    42// 2byte����/����λͼ��Ϣ 
#define c_c_peer_peerfilemap_channelid	// 4byteԭ������
#define c_c_peer_peerfilemap_clientid	// string 
#define c_c_peer_peerfilemap_mapsize    // 4byte
#define c_c_peer_peerfilemap_filemap 	// ������ map

#define c_c_peer_peerfilemap_ack 	   43// 2byte����/����λͼ��Ϣ 
#define c_c_peer_peerfilemap_channelid	// 4byteԭ������
#define c_c_peer_peerfilemap_clientid	// string
#define c_c_peer_peerfilemap_mapsize    // 4byte
#define c_c_peer_peerfilemap_filemap 	// ������ map

#define c_s_peer_peerdata 			    44// 2byte��������block��Ϣ
#define c_s_peer_peerdata_channelid	    // string
#define c_s_peer_peerdata_clientid	    // string 
#define c_s_peer_peerdata_needmap 	    // ���� 4byte(offset)+4byte(len)... 

#define s_c_peer_peerdata 			    45// 2byte����block������Ϣ 
#define s_c_peer_peerdata_channelid	    // string
#define s_c_peer_peerdata_clientid	    // string 
#define s_c_peer_peerdata_datasize      // 4bytes
#define s_c_peer_peerdata_data 		    // 4byte(offset)+(4byte)len+data...
#define s_c_peer_peerdata_status 	    // 4byte 

#define c_c_peer_peerhave 			    46// 2byte���������block��������Peer���͵�֪ͨ��Ϣ 
#define c_c_peer_peerhave_chid 		    // string
#define c_c_peer_peerhave_clientid	    // string 
#define c_c_peer_peerhave_newblkid 	    // blkid(4byte)

#define c_c_peer_datacancel             47// 2byteȡ����������block��Ϣ
#define c_c_peer_datacancel_chid 		// string
#define c_c_peer_datacancel_clientid	// string  
#define c_c_peer_datacancel_cancelblkid // blkid(4byte)

#define c_c_get_media_info	            48//2byte��peer��������ý����Ϣ��Ϣ

#define c_c_get_media_info_respond      49//2byte Peer��Peer�ظ�ý����Ϣ

//////////////////////////////////////////////////////////////////////////
// ��� cmid

// ��natcenter
#define nat_land_request  				4000 // ��½����
#define nat_land_confirm				4001 // ��½��Ӧ

// ��supernode��nbs��
#define nat_heartbeat_request			4002 // ��nbs����������
#define nat_heartbeat_confirm			4003 // ����Ӧ��ֻ�ڴ���ʱ�ذ�

#define nat_direction_request			4004 // ֱ������
#define nat_direction_confirm			4005 // ֱ���ɹ���Ӧ

// ��natcenter
#define nat_center_request				4006 // ��natcenter��ѯpeer��supernode
#define nat_center_confirm				4007 // ��Ӧ

// ��supernode��nbs�� 4008 4009����
#define nat_supernode_request			4008 // ��supernode���ʹ�͸����
#define nat_supernode_confirm			4009 // ����Ӧ

#define nat_topeer_send					4010 // ��peer����͸��Ϣ
#define nat_topeer_confirm				4011 // ��Ϣ��Ӧ

#define nat_hole_connect_request		4012 // �������紩͸
#define nat_hole_connect_confirm		4013 // ��Ϣ��Ӧ

#define nat_quest_peerinfo_request      4014 // ��supernode����peer��Ϣ
#define nat_quest_peerinfo_confirm      4015 // ��Ӧ

#define nat_main_handshke				4016 // ��������ʱ���ͣ���������������

#define nat_center_requestlist			4100 // ��natcenter����������supernode�б�
#define nat_center_requestlist_res		4101 // natcenter����supernode�б�


//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
//����udp������������������
#define udp_nw_layer_cmd 					2000
	#define udp_nw_layer_cmd_main_id 			0	//8 byte
	#define udp_nw_layer_cmd_sub_id 			1	//2 byte
	#define udp_nw_layer_cmd_blk_count 			2	//2 byte
	#define udp_nw_layer_cmd_rddc_count 		3	//2 byte
	#define udp_nw_layer_cmd_reliable 			4	//1 byte 0�ǿɿ� 1�ɿ� 
	#define udp_nw_layer_cmd_rddc_rate			5	//1byte
	#define udp_nw_layer_cmd_data				6	// �䳤 ���� 
	#define udp_nw_layer_cmd_main_all			7
#define udp_nw_layer_ack 						2001
	#define udp_nw_layer_ack_main_id 					0 //8 byte
	#define udp_nw_layer_ack_sub_status 				1 //4 byte
	#define udp_nw_layer_ack_sub_missed_sub_id_list	 	2 //2byte+2byte...sub_id

#define udp_nw_layer_stat_control 						2002
	#define udp_nw_layer_stat_control_status 				0 //4 byte
	#define udp_nw_layer_stat_control_total_blk_count 		1 //2 byte
	#define udp_nw_layer_stat_control_received_blk_count 	2 //2 byte
//////////////////////////////////////////////////////////////////////////

 struct head_t
 {
 	unsigned int length;		//ָ��������ݳ���
 	unsigned char flag;			//0:��� 1:p2p 2:����;3:�����;4:cis��ص�;5:ins���
 	unsigned short type;
 	unsigned short version;
     unsigned int cmdno;
 	unsigned char cmdcount;
 };
#define SUB_CMD_HEAD_LEN 5 //by wangtao: sizeof(short type) + sizeof (int length) 
//������
struct sub_cmd_t
{
	unsigned char type;
	unsigned int length;
	char cmdbuf[0]; 	
};



#pragma pack(pop)


#endif // !_SERVERPROC__H  
