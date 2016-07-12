 //For C++ inheritence
#define GetObjectFunction( object, func ) (void*)*(void**)((int)*(int*)object + func)
#define Director_GameUpdate 0x64
#define HitActor_TouchPlayer 0x0148

#ifndef SMS_H
	#define SMS_H

	#define PRESS_START	0x1000
	#define PRESS_B		0x0200
	#define PRESS_A		0x0100
	#define PRESS_Z		0x0010
	#define PRESS_X		0x0400
	#define PRESS_Y		0x0800
	#define PRESS_DU	0x0008
	#define PRESS_DD	0x0004
	#define PRESS_DL	0x0001
	#define PRESS_DR	0x0002

	#define MARIOFLAG_ALIVE						0x00000001
	#define MARIOFLAG_INVISIBLE					0x00000004
	#define MARIOFLAG_DEAD						0x00000040
	#define MARIOFLAG_SLIP						0x00000080
	#define MARIOFLAG_HASHELMET_FOLLOWCAMERA	0x00001000
	#define MARIOFLAG_HASHELMET					0x00002000
	#define MARIOFLAG_HASFLUDD					0x00008000
	#define MARIOFLAG_SPLASH					0x00010000
	#define MARIOFLAG_PUDDLE					0x00020000
	#define MARIOFLAG_SHIRT						0x00100000
	#define MARIOFLAG_GONE						0x00200000
	
	#define STATE_NUMBER	0x0000000F
	#define STATE_AIRBORN	0x00000800
	#define STATE_CUTSCENE	0x00001000
	#define STATE_STUNNED	0x00002000
	
	#define STATE_RUNNING	0x04000440
	#define STATE_IDLE		0x0C400200
	#define STATE_SPIN		0x00000441
	#define STATE_JUMPSPIN1	0x00000895
	#define STATE_JUMPSPIN2	0x00000896
	#define STATE_JUMP		0x02000880
	#define STATE_JUMPSIDE	0x00000880
	#define STATE_SIDESTEP	0x0C008220
	#define STATE_SWIM		0x000024D7
	#define STATE_DIVE		0x0080088A
	#define STATE_DIVEJUMP	0x02000889
	#define STATE_DIVESLIDE	0x00800456
	#define STATE_CLIMB		0x18100340
	#define STATE_CLIMBUP	0x10100343
	#define STATE_WALLJUMP	0x02000886
	#define STATE_WALLSLIDE 0x000008A7
	#define STATE_HANG		0x3800034B
	#define STATE_HANGCLIMB	0x3000054F
	#define STATE_SLAMSTART	0x008008A9
	#define STATE_SLAM		0x0080023C
	#define STATE_SPRAY		0x0C008220
	#define STATE_THROWN	0x000208B8
	#define STATE_HOVER		0x0000088B
	#define STATE_STUCK		0x0002033C
	#define STATE_TALKING	0x10001308

typedef struct{
	uint16_t buttons;
	uint8_t lanalogx;
	uint8_t lanalogy;
	uint8_t ranalogx;
	uint8_t ranalogy;
	uint16_t u1;
	uint8_t status;
	uint8_t u2;
} Controller;

// MarDirector* mardirector = (MarDirector*)(r13 + 0x9FB8)
typedef struct{
	int u1;
} MarDirector;

typedef struct{
	float x;
	float y;
	float z;
} Vector;

typedef struct{
	void* Type;
	void* u2;
	int u3;
	int u4;
	Vector position;
	int u5;
	void* u6;
	Vector scale;
	Vector direction;
	void* u7;
	void* u8;
	void* u9;
	int u10;
	int u11;
	float u12;
	float u13;
	float u14;
	float u15;
	float u16;
	int u17;
	int u18;
	int u19;
	void* u20;
} HitActor;

typedef struct{
	void* Type;
	void* u2;
	int u3;
	int u4;
	Vector position;
	int u5;
	void* u6;
	Vector scale;
	Vector direction;
	void* u7;
	void* u8;
	void* u9;
	int u10;
	int u11;
	float u12;
	float u13;
	float u14;
	float u15;
	float u16;
	int u17;
	int u18;
	int u19;
	void* u20;
	int u21;
	int u22;
	uint32_t status;
	uint32_t laststatus;
	int statustime;
} MarioActor;

typedef struct{
	float u1;
	float u2;
	float u3;
	float u4;
	float x;
	float y;
	float z;
} Position;

#define ITEMFLAG_STATIC 0x00000010

typedef struct{
	void* Type;
	void* u2;
	int u3;
	int u4;
	Vector position;
	int u5;
	void* u6;
	Vector scale;
	Vector direction;
	void* u7;
	void* u8;
	void* u9;
	int u10;
	int itemtype;
	float u12;
	float u13;
	float u14;
	float u15;
	float u16;
	int u17;
	int u18;
	int u19;
	void* u20;
	//0x74
	int pad1[14];
	Vector velocity;
	int pad2[14];
	int flags;
} ItemActor;

typedef struct {
 int u1;
 float u2;
} Sound;

typedef struct {
	int x1;
	int y1;
	int x2;
	int y2;
} JUTRect;
typedef struct {
	void* type;
	int content[64];
} J2DGrafContext;
typedef struct {
	void* type;
	int content[64];
} J2DOrthoGraph;
typedef struct {
	void* type;
	int content[9];
} J2DPrint;
typedef struct {
	void* type;
} JUTResFont;
typedef struct {
} ResFONT;
typedef struct {
	void* type;
	int pad1[2];
	int flags;
	JUTRect bounds;
	int content[100];
} J2DTextBox;
typedef struct {
	void* type;
	int content[64];
} J2DPane;
typedef struct {
	void* type;
	int content[64];
} J2DScreen;
typedef struct {
	void* type;
} Talk2D;
typedef struct {
	void* type;
} GCConsole;
typedef struct {
	void* type;
} PollutionManager;
typedef struct {
	float a1[4];
	float a2[4];
	float a3[4];
} A3_A4_f;

//Free is done automatically on stage transition
#define malloc(n) __nwa__FUl((n))
#define free(n) __dla__FUl((n))

void GXSetScissor(int x, int y, int x2, int y2);
void GXInvalidateTexAll();

void J2DOrthoGraph_Create(J2DOrthoGraph* targetaddr, JUTRect* view);

void J2DGrafContext_Setup2D(J2DGrafContext* graphics);

void J2DPrint_Create(J2DPrint* targetaddr, JUTResFont* font, int u);
float J2DPrint_GetWidth(J2DPrint* j2dprint, char* text);
void J2DPrint_Initiate(J2DPrint* j2dprint);
void J2DPrint_Print(J2DPrint* j2dprint, int x, int y, char* text, int u1, int u2, int u3);
void J2DPrint_Delete(J2DPrint* j2dprint, int mask);

static JUTResFont* DiscErrorFont = (JUTResFont*)0x812fef60;

#define GameFont (*(ResFONT**)((*(int*)(SceneReference - 0x6038)) + 0x48))
#define GameStrTable (RTOC - 19304)
void J2DTextBox_Create(J2DTextBox* targetaddr, int u1, JUTRect* bounds, ResFONT* font, void* table, int HBinding, int VBinding);
void J2DTextBox_Draw(J2DTextBox* textbox);
void J2DTextBox_Drawii(J2DTextBox* textbox, int a1, int a2);
void J2DTextBox_DrawSelf(J2DTextBox* textbox, int a1, int a2, A3_A4_f* matrix);
void J2DTextBox_SetString(J2DTextBox* textbox, char* string);
char* J2DTextBox_GetStringPtr(J2DTextBox* textbox);
void J2DTextBox_Delete(J2DTextBox* textbox);

void J2DPane_Draw(J2DPane* pane, int a1, int a2, J2DGrafContext* graphics, int a3);
void J2DPane_SetBasePosition(J2DPane* pane, int pos);
void J2DPane_MakeMatrix(J2DPane* pane, int a1, int a2);

void J2DScreen_Draw(J2DScreen* pane, int a1, int a2, J2DGrafContext* graphics, int a3);

void JUTRect_Set(JUTRect* rect, int x, int y, int w, int h);

void MarDirector_SetupObjects(MarDirector* director);
void Drama_PrepareUpdate(HitActor* this, int a1, void* drama, void* graphics, int obj);

/*
typedef ObjItemManager{
	int a1;
	int a2;
	void (*__dt__)();
	void (*GetType)();
	void (*Load)();
	void (*Save)();
	void (*LoadAfter)();
	void (*SearchF)();
	void (*Perform)();
	void (*CreateModelData)();
	void (*CreateModelData)();
	void (*CreateAnmData)();
	void (*CreateModelDataArray)();
	void (*ClipActors)();
	void (*SetFlagOutOfCube)();
	void (*CreateSpcBinary)();
	bool (*HasMapCollision)();
}*/

register void* RTOC	asm ("r2");
register void* SceneReference asm ("r13");

// GC
//static void (*GXSetBlendMode)(int a1, int a2, int a3, int a4) = (void*)0x80361dd0;
//static void (*GXBegin)(int a1, int a2, int a3) = (void*)0x8035df88;

static const Controller* Controllers = (Controller*)0x80404454;
static const Controller* ControllerOne = (Controller*)0x80404454;
static const Controller* ControllerTwo = (Controller*)0x80404460;
static const Controller* ControllerThree = (Controller*)0x8040446c;
static const Controller* ControllerFour = (Controller*)0x80404478;

static void* gpSystemFont = (void*)0x8040e188;
static void* gpRomFont = (void*)0x8040e18c;
static void* gpItemManager = (void*)0x8040df10;

// SMS
static void* gpApplication = (void*)0x803e9700;
static Talk2D** TalkManager = (Talk2D**)0x8040ddd8;
unsigned int CalcKeyCode(char* key);
void Vector_Add(Vector* v1, Vector* v2, Vector* vo);
void Vector_Subtract(Vector* v1, Vector* v2);
void Vector_Normalize(Vector* vi, Vector* vo);
void Vector_Scale(Vector* vi, float scale);
float Vector_Magnitude(Vector* v);
void Talk2D_OpenWindow(Talk2D* talkmanager, int a1, float f1);
void DrawWaterBackground(GCConsole* console);

void StampPollution(PollutionManager* pollution, int stamp, float x, float y, float z, float r);
void CleanPollution(PollutionManager* pollution, float x, float y, float z, float r);

// Stage
static MarDirector** gpMarDirector = (void*)0x8040e178;
static void** gpMap = (void*)0x8040de98;
static PollutionManager** gpPollution = (void*)0x8040ded0;
static void** gpStrategy = (void*)0x8040e080;

void IsPolluted(void);

static uint8_t* ChangeScenario = (void*)0x003e9712;
static uint8_t* ChangeEpisode = (void*)0x003e9713;
void ChangeStage(MarDirector* director, uint32_t stageinfo);
HitActor* SearchF(void* namereflist, int keycode, char* ref);
#define SearchObjByRef(ref) SearchF((void*)*(((int*)*(int*)(SceneReference - 0x5db8)) + 1), CalcKeyCode((ref)), (ref))
int GetShineStage(uint8_t stageid);

// Mario
static HitActor** gpCamera = (void*)0x8040d0a8;
static HitActor** gpMarioAddress = (void*)0x8040e108;
#define GetFludd(mario) (HitActor*)((mario) + 0x03E4)
static Vector** gpMarioPos = (void*)0x8040e10c;
static float** gpMarioAngleX = (void*)0x8040e110;
static float** gpMarioAngleY = (void*)0x8040e114;
static float** gpMarioAngleZ = (void*)0x8040e118;
static float** gpMarioSpeedX = (void*)0x8040e11c;
static float** gpMarioSpeedY = (void*)0x8040e120;
static float** gpMarioSpeedZ = (void*)0x8040e124;
static const uint16_t** gpMarioLightID = (void*)0x8040e128;
static int** gpMarioFlag = (void*)0x8040e12c;
static float** gpMarioThrowPower = (void*)0x8040e130;
static const void*** gpMarioGroundPlane = (void*)0x8040e134;
MarioActor* GetMarioHitActor();
HitActor* GetFLUDD();
HitActor* GetMarioYoshi();
int GetMarioHP();
int GetMarioStatus();
int GetMarioStatusFromHitActor(MarioActor* mario);
void ChangeMarioStatus(MarioActor* mario, int u1, int u2, int u3); 
void incGoldCoinFlag(uint32_t coinptr, int stage, int amount);
#define IncrementCoin(amount) incGoldCoinFlag(*(int*)(SceneReference - 0x6060), GetShineStage((*(int*)(gpApplication + 0x0E)) & 0xFF), (amount))
void GetMarioMapPosition();
void ThrowMario(void*, void*, float, float, float);
void SetMarioAnim(float a1, int a2, int a3);
int IsMarioJumping();
void SetMarioStatus(MarioActor* mario, int a2, int a3, int a4);
#define MarioDoJump(mario) SetMarioStatus((mario), 0x02000881, 0, 0)
#define MarioDoThrow(mario) SetMarioStatus((mario), 0x000208B8, 0, 0)
void EmitSweat(MarioActor* mario);
void Fludd_Emit(HitActor* fludd);
void Mario_StartVoice(MarioActor* mario, int id);
void WearGlasses(MarioActor* mario);

#define MARIOMSG_THROW		0x07
#define MARIOMSG_HURTFIRE	0x0a
#define MARIOMSG_HURT		0x0e
void SendMsgToMario(MarioActor* mario, int msg);

// Objects
static void* ItemManager = (void*)0x8107e3a4;
#define OBJ_WATER			0x20000002
#define OBJ_ONEUP			0x20000006
#define OBJ_COIN			0x2000000E
#define OBJ_BLUECOIN		0x20000010
#define OBJ_ROCKETNOZZLE	0x20000022
#define OBJ_HOVERNOZZLE		0x20000026
#define OBJ_TURBONOZZLE		0x2000002A
HitActor* MakeObjAppear(const void* itemManager, int id);

// Effects
void GenerateEffectElectric(HitActor* pos);

// Music / SFX
void PlaySound(int rate, Sound* sfx, int nl1, int nl2, int nl3, int four);
void StartStageEntranceDemoSeq(int u1, int u2);
void startBGM(int u1);
void stopBGM(int u1);

void DraweMarioHP(MarioActor* emario);

#endif
