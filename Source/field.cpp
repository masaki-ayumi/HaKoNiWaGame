#include "field.h"
#include <assert.h>
#include <DxLib.h>>
#include "debugScreen.h"



Field::Field(SceneBase* scene):GameObject(scene)
{
	hModel = MV1LoadModel("data\\BoxStage_13.mv1");
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
	MV1SetPosition(hSkyModel, VGet(0, -10000, 0));
	MV1DrawModel(hModel);
	MV1DrawModel(hSkyModel);



#if 0	//デバッグ表示
	DebugSetColor(255, 255, 255);
	DebugPrintf(0, 300, "X:%f,Y:%f,Z:%f", position.x,position.y,position.z);
#endif // 0

}

bool Field::CollisoinLine(VECTOR * hit, VECTOR from, VECTOR to)
{
	MV1_COLL_RESULT_POLY collision = MV1CollCheck_Line(hModel, -1, from, to);

#if 0	//デバッグ表示
	DebugSetColor(255, 255, 255);
	DebugPrintf(0, 200, "地形レイ衝突:%d", collision.HitFlag);
#endif // 0


	if (collision.HitFlag == 0)
		return false;
	*hit = collision.HitPosition;
	return true;
}

bool Field::CollisoinSphere(VECTOR * hit, VECTOR position)
{
	position = VAdd(position, VGet(0, 10, 0));
	MV1_COLL_RESULT_POLY_DIM collision = MV1CollCheck_Sphere(hModel, -1, position, 5);

#if 0	//デバッグ表示
	DebugSetColor(255, 255, 255);
	DebugPrintf(0, 220, "地形球衝突:%d", collision.HitNum);
#endif // 0

	if (collision.HitNum == 0)
		return false;
	return true;
}
