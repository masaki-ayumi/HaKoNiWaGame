#include "field.h"
#include <assert.h>
#include <DxLib.h>>
#include "debugScreen.h"



Field::Field(SceneBase* scene):GameObject(scene)
{
	hModel = MV1LoadModel("data\\BoxStage_13.mv1");
	//hModel = MV1LoadModel("data\\Stage\\Stage00.mv1");
	assert(hModel > 0);
	hSkyModel = MV1LoadModel("data\\Stage\\Stage00_sky.mv1");
	assert(hSkyModel > 0);

	
}

Field::~Field()
{
	MV1DeleteModel(hModel);
	MV1DeleteModel(hSkyModel);
}

void Field::Update()
{


	//int meshNum = 0;
	//meshNum = MV1GetMeshNum(hModel);
	//VECTOR meshMaxPos;
	//VECTOR meshMinPos;
	//for (int i = 0; i < meshNum; i++)
	//{
	//	meshMaxPos = MV1GetMeshMaxPosition(hModel, i);
	//	meshMinPos = MV1GetMeshMinPosition(hModel, i);
	//
	//	position.x = (meshMaxPos.x + meshMinPos.x) / 2;
	//	position.y = (meshMaxPos.y + meshMinPos.y) / 2;
	//	position.z = (meshMaxPos.z + meshMinPos.z) / 2;
	//}
}

void Field::Draw()
{
	MV1SetPosition(hSkyModel, VGet(0, -10000, 0));
	//メッシュの最大と最小の平均をとってそこに移動してみる
	//MV1SetPosition(hSkyModel, position);
	MV1DrawModel(hModel);
	MV1DrawModel(hSkyModel);

	DebugSetColor(255, 255, 255);
	DebugPrintf(0, 300, "X:%f,Y:%f,Z:%f", position.x,position.y,position.z);

}

bool Field::CollisoinLine(VECTOR * hit, VECTOR from, VECTOR to)
{
	MV1_COLL_RESULT_POLY collision = MV1CollCheck_Line(hModel, -1, from, to);
	DebugSetColor(255, 255, 255);
	DebugPrintf(0, 200, "地形レイ衝突:%d", collision.HitFlag);
	if (collision.HitFlag == 0)
		return false;
	*hit = collision.HitPosition;
	return true;
}

bool Field::CollisoinSphere(VECTOR * hit, VECTOR position)
{
	position = VAdd(position, VGet(0, 10, 0));
	MV1_COLL_RESULT_POLY_DIM collision = MV1CollCheck_Sphere(hModel, -1, position, 5);
	DebugSetColor(255, 255, 255);
	DebugPrintf(0, 220, "地形球衝突:%d", collision.HitNum);
	if (collision.HitNum == 0)
		return false;
	//*hit = collision.Dim->HitPosition;
	return true;
}
