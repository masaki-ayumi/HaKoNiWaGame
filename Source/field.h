#pragma once
#include "../Library/gameObject.h"
class Field : public  GameObject
{
public:
	Field(SceneBase* scene);
	~Field();
	void Update();
	void Draw();

	int hModel;	//地形モデル用ハンドル
	int hSkyModel;	//空モデル用ハンドル
};