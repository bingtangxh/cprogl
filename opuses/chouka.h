#include <stdbool.h>

typedef uint32_t RoleMeta;

#define ROLE_TYPE_TRAVELER_AETHER   0
#define ROLE_TYPE_TRAVELER_LUMINE   1
#define ROLE_TYPE_COLLAB            2
#define ROLE_TYPE_FOUR_STAR         4
#define ROLE_TYPE_LIMITED_FIVE_STAR 5

// 编码池信息（常驻五星时才有意义）
#define ENCODE_POOL_VERSION(major, minor, half) \
    (((major) << 6) | ((minor) << 2) | ((half) & 0x3))

// 构造 RoleMeta：常驻五星 = (encoded << 3) | 3（3表示常驻五星）
// 只看最后两位，如果是 3 ，表示是常驻五星，再去解码
// 如果往前全是 0 ，说明是开服常驻，从未 UP （刻晴是特殊情况）
#define MAKE_ROLE_META(major, minor, half) \
    ((ENCODE_POOL_VERSION((major), (minor), (half)) << 3) | 3)

// 提取 roleType
#define GET_ROLE_TYPE(meta) ((meta) & 0x7)

// 提取常驻五星的首次UP信息（前提是 GET_ROLE_TYPE(meta) == 3）
#define GET_MAJOR(meta) (((meta) >> 9) & 0xFF)
#define GET_MINOR(meta) (((meta) >> 5) & 0x0F)
#define GET_HALF(meta)  (((meta) >> 3) & 0x03)


typedef struct characterMap {
    const unsigned int id;
    const wchar_t name_cn[20];
    const char name[40];
    const uint32_t attrib;
    /*
    0: traveler Aether
    1: traveler Lumine
    2: interaction such as Eloi
    3: permanent 5 star
    4: 4 star
    5: limited 5 star
    */
}Char_Map;

typedef struct weaponMap {
    const unsigned int id;
    const wchar_t name_cn[20];
    const char name[40];
    const unsigned int stars;
} WeaponMap;

typedef struct wishPool {
    unsigned int up5[24];
    unsigned int up4[24];
    unsigned int weapon[24];
    uint8_t major;
    uint8_t minor;
    uint8_t half;
    uint8_t startY;
    uint8_t endY;
    uint8_t startM;
    uint8_t endM;
    uint8_t startD;
    uint8_t endD;
} Wish_Pool;

Char_Map CharMap[]={
    {0,L"空","Aether",0},
    {1,L"荧","Lumine",1},
    {2,L"安柏","Amber",4},
    {3,L"凯亚","Kaeya",4},
    {4,L"丽莎","Lisa",4},
    {5,L"芭芭拉","Barbara",4},
    {6,L"雷泽","Razor",4},
    {7,L"香菱","Xiangling",4},
    {8,L"北斗","Beidou",4},
    {9,L"行秋","Xingqiu",4},
    {10,L"凝光","Ningguang",4},
    {11,L"菲谢尔","Fischl",4},
    {12,L"班尼特","Bennett",4},
    {13,L"诺艾尔","Noelle",4},
    {14,L"重云","Chongyun",4},
    {15,L"砂糖","Sucrose",4},
    {16,L"琴","Jean",3},
    {17,L"迪卢克","Diluc",3},
    {18,L"七七","Qiqi",3},
    {19,L"莫娜","Mona",3},
    {20,L"刻晴","Keqing",MAKE_ROLE_META(1,3,2)},
    {21,L"温迪","Venti",5},
    {22,L"可莉","Klee",5},
    {23,L"迪奥娜","Diona",4},
    {24,L"达达利亚","Tartaglia",5},
    {25,L"辛焱","Xinyan",4},
    {26,L"钟离","Zhongli",5},
    {27,L"阿贝多","Albedo",5},
    {28,L"甘雨","Ganyu",5},
    {29,L"魈","Xiao",5},
    {30,L"胡桃","Hutao",5},
    {31,L"罗莎莉亚","Rosaria",4},
    {32,L"烟绯","Yanfei",4},
    {33,L"优菈","Eula",5},
    {34,L"枫原万叶","Kaedehara Kazuha",5},
    {35,L"神里绫华","Kamisato Ayaka",5},
    {36,L"早柚","Sayu",4},
    {37,L"宵宫","Yoimiya",5},
    {38,L"埃洛伊","Eloi",2},
    {39,L"九条裟罗","Kujou Sara",4},
    {40,L"雷电将军","Raiden Shogun",5},
    {41,L"珊瑚宫心海","Sangonomiya Kokomi",5},
    {42,L"托马","Thoma",4},
    {43,L"五郎","Gorou",4},
    {44,L"荒泷一斗","Arataki Itto",5},
    {45,L"云堇","Yunjin",4},
    {46,L"申鹤","Shenhe",5},
    {47,L"八重神子","Yae Miko",5},
    {48,L"神里绫人","Kamisato Ayato",5},
    {49,L"夜兰","Yelan",5},
    {50,L"久岐忍","Kuki Shinobu",4},
    {51,L"鹿野院平藏","Shikanoin Heizou",4},
    {52,L"柯莱","Collei",4},
    {53,L"提纳里","Tighnari",MAKE_ROLE_META(3,0,1)},
    {54,L"多莉","Dori",4},
    {55,L"坎蒂丝","Candace",4},
    {56,L"赛诺","Cyno",5},
    {57,L"妮露","Nilou",5},
    {58,L"纳西妲","Nahida",5},
    {59,L"莱依拉","Layla",4},
    {60,L"珐露珊","Faruzan",4},
    {61,L"流浪者","Wanderer",5},
    {62,L"瑶瑶","Yaoyao",4},
    {63,L"艾尔海森","Alhaitham",5},
    {64,L"迪希雅","Dehya",MAKE_ROLE_META(3,5,1)},
    {65,L"米卡","Mika",4},
    {66,L"卡维","Kaveh",4},
    {67,L"白术","Baizhu",5},
    {68,L"绮良良","Kirara",4},
    {69,L"琳妮特","Lynette",4},
    {70,L"林尼","Lyney",5},
    {71,L"菲米尼","Freminet",4},
    {72,L"那维莱特","Neuvillette",5},
    {73,L"莱欧斯利","Wriothesley",5},
    {74,L"夏洛蒂","Charlotte",4},
    {75,L"芙宁娜","Furina",5},
    {76,L"娜维娅","Navia",5},
    {77,L"夏沃蕾","Chevreuse",4},
    {78,L"嘉明","Gaming",4},
    {79,L"闲云","Xianyun",5},
    {80,L"千织","Chiori",5},
    {81,L"阿蕾奇诺","Arlecchino",5},
    {82,L"赛索斯","Sethos",4},
    {83,L"克洛琳德","Clorinde",5},
    {84,L"希格雯","Sigewinne",5},
    {85,L"艾梅莉埃","Emilie",5},
    {86,L"卡齐娜","Kachina",4},
    {87,L"玛拉妮","Mualani",5},
    {88,L"基尼奇","Kinich",5},
    {89,L"希诺宁","Xilonen",5},
    {90,L"欧洛伦","Ororon",4},
    {91,L"恰斯卡","Chasca",5},
    {92,L"茜特菈莉","Citlali",5},
    {93,L"玛薇卡","Mavuika",5},
    {94,L"蓝砚","Lan Yan",4},
    {95,L"梦见月瑞希","Yumemizuki Mizuki",MAKE_ROLE_META(5,4,1)},
    {96,L"伊安珊","Iansan",4},
    {97,L"瓦雷莎","Varesa",5},
    {98,L"伊法","Ifa",4},
    {99,L"爱可菲","Escoffier",5},
    {100,L"塔利雅","Dahlia",4},
    {101,L"丝柯克","Skirk",5},
    {102,L"伊涅芙","Ineffa",5}
};

Wish_Pool WishPool[]={
    {{21},{11,7,5},{},1,0,1,2020,9,28,2020,10,18},
    {{22},{15,9,13},{},1,0,2,2020,10,20,2020,11,10},
    {{24},{8,10,23},{},1,1,1,2020,11,11,2020,12,1},
    {{26},{6,14,25},{},1,1,2,2020,12,1,2020,12,22},
    {{27},{15,11,12},{},1,2,1,2020,12,23,2021,01,12},
    {{28},{7,9,13},{},1,2,2,2021,1,12,2021,2,2},
    {{29},{8,25,23},{},1,3,1,2021,2,3,2021,2,17},
    {{20},{12,10,5},{},1,3,2,2021,2,17,2021,3,2},
    {{30},{7,9,14},{},1,3,3,2021,3,2,2021,3,16},
    {{21},{6,15,13},{},1,4,1,2021,3,17,2021,4,6},
    {{24},{5,11,31},{},1,4,2,2021,4,6,0,0,0},
    {{26},{32,13,23}}
};