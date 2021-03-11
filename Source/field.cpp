#include "field.h"
#include <assert.h>

Field::Field(SceneBase * scene)
{
	hModel = MV1LoadModel("data\\BoxStage.mv1");
	assert(hModel > 0);
	hSkyModel = MV1LoadModel("data\\Stage\\Stage00_sky.mv1");
	assert(hSkyModel > 0);
	//int center = MV1SearchFrame(hModel, "Cubes");
	//MV1SetFrameUserLocalMatrix(hModel, center, MGetRotY(DX_PI_F));
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
	MV1DrawModel(hModel);
	MV1DrawModel(hSkyModel);
}
