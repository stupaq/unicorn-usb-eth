#include "../include/crc.h"

//-----------------------------------------------------------------------------
//	32 bit CRC support routines
//
// CRC Routines from  net/wan/sbni.c)
// table generated by Rocksoft^tm Model CRC Algorithm Table Generation Program V1.0
//
//-----------------------------------------------------------------------------
#define CRC32_REMAINDER 0xCBF43926
#define CRC32(c,crc) (crc32tab[((unsigned long)(crc>>24) ^ (c)) & 0xff] ^ (((crc) << 8)))
const unsigned long  crc32tab[256] =
{
    0x00000000L, 0x04C11DB7L, 0x09823B6EL, 0x0D4326D9L,
    0x130476DCL, 0x17C56B6BL, 0x1A864DB2L, 0x1E475005L,
    0x2608EDB8L, 0x22C9F00FL, 0x2F8AD6D6L, 0x2B4BCB61L,
    0x350C9B64L, 0x31CD86D3L, 0x3C8EA00AL, 0x384FBDBDL,
    0x4C11DB70L, 0x48D0C6C7L, 0x4593E01EL, 0x4152FDA9L,
    0x5F15ADACL, 0x5BD4B01BL, 0x569796C2L, 0x52568B75L,
    0x6A1936C8L, 0x6ED82B7FL, 0x639B0DA6L, 0x675A1011L,
    0x791D4014L, 0x7DDC5DA3L, 0x709F7B7AL, 0x745E66CDL,
    0x9823B6E0L, 0x9CE2AB57L, 0x91A18D8EL, 0x95609039L,
    0x8B27C03CL, 0x8FE6DD8BL, 0x82A5FB52L, 0x8664E6E5L,
    0xBE2B5B58L, 0xBAEA46EFL, 0xB7A96036L, 0xB3687D81L,
    0xAD2F2D84L, 0xA9EE3033L, 0xA4AD16EAL, 0xA06C0B5DL,
    0xD4326D90L, 0xD0F37027L, 0xDDB056FEL, 0xD9714B49L,
    0xC7361B4CL, 0xC3F706FBL, 0xCEB42022L, 0xCA753D95L,
    0xF23A8028L, 0xF6FB9D9FL, 0xFBB8BB46L, 0xFF79A6F1L,
    0xE13EF6F4L, 0xE5FFEB43L, 0xE8BCCD9AL, 0xEC7DD02DL,
    0x34867077L, 0x30476DC0L, 0x3D044B19L, 0x39C556AEL,
    0x278206ABL, 0x23431B1CL, 0x2E003DC5L, 0x2AC12072L,
    0x128E9DCFL, 0x164F8078L, 0x1B0CA6A1L, 0x1FCDBB16L,
    0x018AEB13L, 0x054BF6A4L, 0x0808D07DL, 0x0CC9CDCAL,
    0x7897AB07L, 0x7C56B6B0L, 0x71159069L, 0x75D48DDEL,
    0x6B93DDDBL, 0x6F52C06CL, 0x6211E6B5L, 0x66D0FB02L,
    0x5E9F46BFL, 0x5A5E5B08L, 0x571D7DD1L, 0x53DC6066L,
    0x4D9B3063L, 0x495A2DD4L, 0x44190B0DL, 0x40D816BAL,
    0xACA5C697L, 0xA864DB20L, 0xA527FDF9L, 0xA1E6E04EL,
    0xBFA1B04BL, 0xBB60ADFCL, 0xB6238B25L, 0xB2E29692L,
    0x8AAD2B2FL, 0x8E6C3698L, 0x832F1041L, 0x87EE0DF6L,
    0x99A95DF3L, 0x9D684044L, 0x902B669DL, 0x94EA7B2AL,
    0xE0B41DE7L, 0xE4750050L, 0xE9362689L, 0xEDF73B3EL,
    0xF3B06B3BL, 0xF771768CL, 0xFA325055L, 0xFEF34DE2L,
    0xC6BCF05FL, 0xC27DEDE8L, 0xCF3ECB31L, 0xCBFFD686L,
    0xD5B88683L, 0xD1799B34L, 0xDC3ABDEDL, 0xD8FBA05AL,
    0x690CE0EEL, 0x6DCDFD59L, 0x608EDB80L, 0x644FC637L,
    0x7A089632L, 0x7EC98B85L, 0x738AAD5CL, 0x774BB0EBL,
    0x4F040D56L, 0x4BC510E1L, 0x46863638L, 0x42472B8FL,
    0x5C007B8AL, 0x58C1663DL, 0x558240E4L, 0x51435D53L,
    0x251D3B9EL, 0x21DC2629L, 0x2C9F00F0L, 0x285E1D47L,
    0x36194D42L, 0x32D850F5L, 0x3F9B762CL, 0x3B5A6B9BL,
    0x0315D626L, 0x07D4CB91L, 0x0A97ED48L, 0x0E56F0FFL,
    0x1011A0FAL, 0x14D0BD4DL, 0x19939B94L, 0x1D528623L,
    0xF12F560EL, 0xF5EE4BB9L, 0xF8AD6D60L, 0xFC6C70D7L,
    0xE22B20D2L, 0xE6EA3D65L, 0xEBA91BBCL, 0xEF68060BL,
    0xD727BBB6L, 0xD3E6A601L, 0xDEA580D8L, 0xDA649D6FL,
    0xC423CD6AL, 0xC0E2D0DDL, 0xCDA1F604L, 0xC960EBB3L,
    0xBD3E8D7EL, 0xB9FF90C9L, 0xB4BCB610L, 0xB07DABA7L,
    0xAE3AFBA2L, 0xAAFBE615L, 0xA7B8C0CCL, 0xA379DD7BL,
    0x9B3660C6L, 0x9FF77D71L, 0x92B45BA8L, 0x9675461FL,
    0x8832161AL, 0x8CF30BADL, 0x81B02D74L, 0x857130C3L,
    0x5D8A9099L, 0x594B8D2EL, 0x5408ABF7L, 0x50C9B640L,
    0x4E8EE645L, 0x4A4FFBF2L, 0x470CDD2BL, 0x43CDC09CL,
    0x7B827D21L, 0x7F436096L, 0x7200464FL, 0x76C15BF8L,
    0x68860BFDL, 0x6C47164AL, 0x61043093L, 0x65C52D24L,
    0x119B4BE9L, 0x155A565EL, 0x18197087L, 0x1CD86D30L,
    0x029F3D35L, 0x065E2082L, 0x0B1D065BL, 0x0FDC1BECL,
    0x3793A651L, 0x3352BBE6L, 0x3E119D3FL, 0x3AD08088L,
    0x2497D08DL, 0x2056CD3AL, 0x2D15EBE3L, 0x29D4F654L,
    0xC5A92679L, 0xC1683BCEL, 0xCC2B1D17L, 0xC8EA00A0L,
    0xD6AD50A5L, 0xD26C4D12L, 0xDF2F6BCBL, 0xDBEE767CL,
    0xE3A1CBC1L, 0xE760D676L, 0xEA23F0AFL, 0xEEE2ED18L,
    0xF0A5BD1DL, 0xF464A0AAL, 0xF9278673L, 0xFDE69BC4L,
    0x89B8FD09L, 0x8D79E0BEL, 0x803AC667L, 0x84FBDBD0L,
    0x9ABC8BD5L, 0x9E7D9662L, 0x933EB0BBL, 0x97FFAD0CL,
    0xAFB010B1L, 0xAB710D06L, 0xA6322BDFL, 0xA2F33668L,
    0xBCB4666DL, 0xB8757BDAL, 0xB5365D03L, 0xB1F740B4L
};

//------------------------------------------------------------------------------
//	crc32
//------------------------------------------------------------------------------
unsigned long crc32(unsigned long initial, unsigned char *mem, int len)
{
    unsigned long crc;
    crc = initial;
    for(;len;mem++,len--) {
        crc = CRC32(*mem, crc);
    }
    return(crc);
}

//-----------------------------------------------------------------------------
//	10 bit CRC support routines
//-----------------------------------------------------------------------------
const unsigned short crc10tab[256] = {
0x0000, 0x0233, 0x0255, 0x0066, 0x0299, 0x00aa, 0x00cc, 0x02ff, 
0x0301, 0x0132, 0x0154, 0x0367, 0x0198, 0x03ab, 0x03cd, 0x01fe, 
0x0031, 0x0202, 0x0264, 0x0057, 0x02a8, 0x009b, 0x00fd, 0x02ce, 
0x0330, 0x0103, 0x0165, 0x0356, 0x01a9, 0x039a, 0x03fc, 0x01cf, 
0x0062, 0x0251, 0x0237, 0x0004, 0x02fb, 0x00c8, 0x00ae, 0x029d, 
0x0363, 0x0150, 0x0136, 0x0305, 0x01fa, 0x03c9, 0x03af, 0x019c, 
0x0053, 0x0260, 0x0206, 0x0035, 0x02ca, 0x00f9, 0x009f, 0x02ac, 
0x0352, 0x0161, 0x0107, 0x0334, 0x01cb, 0x03f8, 0x039e, 0x01ad, 
0x00c4, 0x02f7, 0x0291, 0x00a2, 0x025d, 0x006e, 0x0008, 0x023b, 
0x03c5, 0x01f6, 0x0190, 0x03a3, 0x015c, 0x036f, 0x0309, 0x013a, 
0x00f5, 0x02c6, 0x02a0, 0x0093, 0x026c, 0x005f, 0x0039, 0x020a, 
0x03f4, 0x01c7, 0x01a1, 0x0392, 0x016d, 0x035e, 0x0338, 0x010b, 
0x00a6, 0x0295, 0x02f3, 0x00c0, 0x023f, 0x000c, 0x006a, 0x0259, 
0x03a7, 0x0194, 0x01f2, 0x03c1, 0x013e, 0x030d, 0x036b, 0x0158, 
0x0097, 0x02a4, 0x02c2, 0x00f1, 0x020e, 0x003d, 0x005b, 0x0268, 
0x0396, 0x01a5, 0x01c3, 0x03f0, 0x010f, 0x033c, 0x035a, 0x0169, 
0x0188, 0x03bb, 0x03dd, 0x01ee, 0x0311, 0x0122, 0x0144, 0x0377, 
0x0289, 0x00ba, 0x00dc, 0x02ef, 0x0010, 0x0223, 0x0245, 0x0076, 
0x01b9, 0x038a, 0x03ec, 0x01df, 0x0320, 0x0113, 0x0175, 0x0346, 
0x02b8, 0x008b, 0x00ed, 0x02de, 0x0021, 0x0212, 0x0274, 0x0047, 
0x01ea, 0x03d9, 0x03bf, 0x018c, 0x0373, 0x0140, 0x0126, 0x0315, 
0x02eb, 0x00d8, 0x00be, 0x028d, 0x0072, 0x0241, 0x0227, 0x0014, 
0x01db, 0x03e8, 0x038e, 0x01bd, 0x0342, 0x0171, 0x0117, 0x0324, 
0x02da, 0x00e9, 0x008f, 0x02bc, 0x0043, 0x0270, 0x0216, 0x0025, 
0x014c, 0x037f, 0x0319, 0x012a, 0x03d5, 0x01e6, 0x0180, 0x03b3, 
0x024d, 0x007e, 0x0018, 0x022b, 0x00d4, 0x02e7, 0x0281, 0x00b2, 
0x017d, 0x034e, 0x0328, 0x011b, 0x03e4, 0x01d7, 0x01b1, 0x0382, 
0x027c, 0x004f, 0x0029, 0x021a, 0x00e5, 0x02d6, 0x02b0, 0x0083, 
0x012e, 0x031d, 0x037b, 0x0148, 0x03b7, 0x0184, 0x01e2, 0x03d1, 
0x022f, 0x001c, 0x007a, 0x0249, 0x00b6, 0x0285, 0x02e3, 0x00d0, 
0x011f, 0x032c, 0x034a, 0x0179, 0x0386, 0x01b5, 0x01d3, 0x03e0, 
0x021e, 0x002d, 0x004b, 0x0278, 0x0087, 0x02b4, 0x02d2, 0x00e1
};

//------------------------------------------------------------------------------
//	crc10
//------------------------------------------------------------------------------
unsigned short crc10(unsigned short crc, unsigned char *mem, int len)
{
    int i;
    
    for (i=0; i<len; i++) {
        crc = ((crc<<8) & 0x3ff) ^ crc10tab[(crc>>2) & 0xff] ^ *mem++;
    }
    return crc;
}

//-----------------------------------------------------------------------------
//	8 bit HEC support routines
//-----------------------------------------------------------------------------
const unsigned char hecTab[256] = {
0x00, 0x07, 0x0e, 0x09, 0x1c, 0x1b, 0x12, 0x15, 
0x38, 0x3f, 0x36, 0x31, 0x24, 0x23, 0x2a, 0x2d, 
0x70, 0x77, 0x7e, 0x79, 0x6c, 0x6b, 0x62, 0x65, 
0x48, 0x4f, 0x46, 0x41, 0x54, 0x53, 0x5a, 0x5d, 
0xe0, 0xe7, 0xee, 0xe9, 0xfc, 0xfb, 0xf2, 0xf5, 
0xd8, 0xdf, 0xd6, 0xd1, 0xc4, 0xc3, 0xca, 0xcd, 
0x90, 0x97, 0x9e, 0x99, 0x8c, 0x8b, 0x82, 0x85, 
0xa8, 0xaf, 0xa6, 0xa1, 0xb4, 0xb3, 0xba, 0xbd, 
0xc7, 0xc0, 0xc9, 0xce, 0xdb, 0xdc, 0xd5, 0xd2, 
0xff, 0xf8, 0xf1, 0xf6, 0xe3, 0xe4, 0xed, 0xea, 
0xb7, 0xb0, 0xb9, 0xbe, 0xab, 0xac, 0xa5, 0xa2, 
0x8f, 0x88, 0x81, 0x86, 0x93, 0x94, 0x9d, 0x9a, 
0x27, 0x20, 0x29, 0x2e, 0x3b, 0x3c, 0x35, 0x32, 
0x1f, 0x18, 0x11, 0x16, 0x03, 0x04, 0x0d, 0x0a, 
0x57, 0x50, 0x59, 0x5e, 0x4b, 0x4c, 0x45, 0x42, 
0x6f, 0x68, 0x61, 0x66, 0x73, 0x74, 0x7d, 0x7a, 
0x89, 0x8e, 0x87, 0x80, 0x95, 0x92, 0x9b, 0x9c, 
0xb1, 0xb6, 0xbf, 0xb8, 0xad, 0xaa, 0xa3, 0xa4, 
0xf9, 0xfe, 0xf7, 0xf0, 0xe5, 0xe2, 0xeb, 0xec, 
0xc1, 0xc6, 0xcf, 0xc8, 0xdd, 0xda, 0xd3, 0xd4, 
0x69, 0x6e, 0x67, 0x60, 0x75, 0x72, 0x7b, 0x7c, 
0x51, 0x56, 0x5f, 0x58, 0x4d, 0x4a, 0x43, 0x44, 
0x19, 0x1e, 0x17, 0x10, 0x05, 0x02, 0x0b, 0x0c, 
0x21, 0x26, 0x2f, 0x28, 0x3d, 0x3a, 0x33, 0x34, 
0x4e, 0x49, 0x40, 0x47, 0x52, 0x55, 0x5c, 0x5b, 
0x76, 0x71, 0x78, 0x7f, 0x6a, 0x6d, 0x64, 0x63, 
0x3e, 0x39, 0x30, 0x37, 0x22, 0x25, 0x2c, 0x2b, 
0x06, 0x01, 0x08, 0x0f, 0x1a, 0x1d, 0x14, 0x13, 
0xae, 0xa9, 0xa0, 0xa7, 0xb2, 0xb5, 0xbc, 0xbb, 
0x96, 0x91, 0x98, 0x9f, 0x8a, 0x8d, 0x84, 0x83, 
0xde, 0xd9, 0xd0, 0xd7, 0xc2, 0xc5, 0xcc, 0xcb, 
0xe6, 0xe1, 0xe8, 0xef, 0xfa, 0xfd, 0xf4, 0xf3
}; 
unsigned char hecCompute(unsigned char *p)
{
	unsigned char hec = 0;
	int i;
	for(i=0; i<4; i++) {
		hec = hecTab[hec^(*p++)];
	}
	return hec^0x55;
}

int hecCheck(unsigned char *p)
{
	unsigned char hec = 0;
	int i;
	for(i=0; i<4; i++) {
            hec = hecTab[hec^*p++];
	}
	return (hec^0x55)==(*p);
}
