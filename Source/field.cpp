#include "field.h"
#include <assert.h>
#include <DxLib.h>>
#include "debugScreen.h"


Field::Field(SceneBase* scene)
{
	hModel = MV1LoadModel("data\\BoxStage_01.mv1");
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
}

void Field::Draw()
{
	MV1SetPosition(hModel, VGet(0, 0, 0));
	MV1DrawModel(hModel);
	MV1DrawModel(hSkyModel);
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
	MV1_COLL_RESULT_POLY_DIM collision = MV1CollCheck_Sphere(hModel, -1, position, 10);
	DebugSetColor(255, 255, 255);
	DebugPrintf(0, 220, "地形球衝突:%d", collision.HitNum);
	if (collision.HitNum == 0)
		return false;
	*hit = collision.Dim->HitPosition;
	return true;
}
