#include "field.h"
#include <assert.h>

Field::Field(SceneBase * scene)
{
	hModel = MV1LoadModel("data\\BoxStage.mv1");
	assert(hModel > 0);
}

Field::~Field()
{
}

void Field::Update()
{
}

void Field::Draw()
{
	MV1DrawModel(hModel);
}
