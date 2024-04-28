#include<stdint.h>


#define NVR0_ADDR 0X00080000
#define NVR7_ADDR 0X00080700
#define MNVR_ADDR 0X00080800

#define PARAM_START_ADDR            NVR7_ADDR   //NVR4

// #define PARAM_START_ADDR            0x00080400   //NVR4
// #define RSL15_512_FLASH_START_ADDR  0X00100000
#define RSL15_512_FLASH_START_ADDR  PARAM_START_ADDR


/* ------------------------------------------------------------------------ */
/* Flash                : 284 kBytes or 512 kBytes                          */
/* ------------------------------------------------------------------------ */
#define FLASH0_CODE_BASE                0x00100000
#define FLASH0_CODE_RSL15_284_TOP       0x00141FFF
#define FLASH0_CODE_RSL15_284_SIZE      (FLASH0_CODE_RSL15_284_TOP - FLASH0_CODE_BASE + 1)

#define FLASH0_CODE_TOP                 0x00157FFF
#define FLASH0_CODE_SIZE                (FLASH0_CODE_TOP - FLASH0_CODE_BASE + 1)

#define FLASH0_DATA_BASE                0x00158000
#define FLASH0_DATA_RSL15_284_TOP       0x0015CFFF
#define FLASH0_DATA_RSL15_284_SIZE      (FLASH0_DATA_RSL15_284_TOP - FLASH0_DATA_BASE + 1)

#define FLASH0_DATA_TOP                 0x0017FFFF
#define FLASH0_DATA_SIZE                (FLASH0_DATA_TOP - FLASH0_DATA_BASE + 1)





/* Memory reservations for security and Bluetooth use cases */
#define RESERVED_FOR_ALL_CONFIG_SIZE       (FLASH_DEU_RESERVED_SIZE+FLASH_BOND_INFO_SIZE+0x800*2)  //jhear
#define FLASH_DEU_RESERVED_BASE         (FLASH0_DATA_TOP+1-RESERVED_FOR_ALL_CONFIG_SIZE) //FLASH0_DATA_BASE
#define FLASH_DEU_RESERVED_SIZE         0xC00
#define FLASH_DEU_RESERVED_TOP          (FLASH_DEU_RESERVED_BASE + FLASH_DEU_RESERVED_SIZE - 1)//(FLASH0_DATA_BASE + FLASH_DEU_RESERVED_SIZE - 1)



#define FLASH_BOND_INFO_BASE            (FLASH_DEU_RESERVED_TOP + 1)
#define FLASH_BOND_INFO_SIZE            0x800
#define FLASH_BOND_INFO_TOP                 (FLASH_BOND_INFO_BASE + FLASH_BOND_INFO_SIZE - 1)
#define FLASH_DATA_CONFIG_BASE            	(FLASH_BOND_INFO_TOP + 1+0x400)



#define FLASH_ADDR_CONFIG	  				FLASH_DATA_CONFIG_BASE  

#define SN_LEN			14U


struct pcba_factory_config_t  //pcba manufacture
{
	uint32_t tmp;// align 4 bytes
	uint8_t pcba_sn_buffer[14];    //add for pcba
	uint8_t pcba_date_buffer[5];
	uint8_t hardware_version_buffer[5];

};


struct factory_config_t   //cgm product
{
	uint32_t tmp;// align 4 bytes
	uint8_t sn_buffer[14];
	uint8_t sensor_lot_buffer[9];
	uint8_t date_buffer[9];
	uint8_t fc_buffer[2];   //sensor correct code
	uint8_t hardware_version_buffer[5];

};


extern struct factory_config_t g_factory_config;