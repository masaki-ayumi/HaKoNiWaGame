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
	VECTOR position;	//プレイヤーの座標
	VECTOR rotation;	//プレイヤーの回転
	int hModel;			//プレイヤーのモデル用ハンドル
};