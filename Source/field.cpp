#include "field.h"
#include <assert.h>
#include <DxLib.h>>

Field::Field(SceneBase* scene)
{
	hModel = MV1LoadModel("data\\BoxStage.mv1");
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
	MV1SetPosition(hModel, VGet(-300, 0, 0));
	MV1DrawModel(hModel);
	MV1DrawModel(hSkyModel);
}

bool Field::CollisoinLine(VECTOR * hit, VECTOR from, VECTOR to)
{
	MV1_COLL_RESULT_POLY collision = MV1CollCheck_Line(hModel, -1, from, to);
	if (collision.HitFlag == 0)
		return false;
	*hit = collision.HitPosition;
	return true;
}

