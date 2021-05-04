#pragma once
#include <DxLib.h>
#include "../Library/gameObject.h"

class Player:public GameObject
{
public:
	Player(SceneBase* scene);
	~Player();
	void Update() override;
	void Draw() override;

private:
	VECTOR position;	//�v���C���[�̍��W
	VECTOR rotation;	//�v���C���[�̉�]
	int hModel;			//�v���C���[�̃��f���p�n���h��
};