#pragma once
#include "../Library/gameObject.h"
class Field : public  GameObject
{
public:
	Field(SceneBase* scene);
	~Field();
	void Update();
	void Draw();

	int hModel;	//�n�`���f���p�n���h��
	int hSkyModel;	//�󃂃f���p�n���h��
};