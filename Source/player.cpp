#include "player.h"
#include <assert.h>
#include <DxLib.h>
#include "field.h"
#include "debugScreen.h"


Player::Player(SceneBase * scene):GameObject(scene)
{
	hModel = MV1LoadModel("data\\MMD用踊る猫ver1.02\\茶ブチねこ.pmx");
	assert(hModel > 0);
	int centor = MV1SearchFrame(hModel, "全ての親");
	MV1SetFrameUserLocalMatrix(hModel, centor, MGetRotY(DX_PI_F));

	position = VGet(0, 0, 0);
	rotation = VGet(0, 0, 0);
}

Player::~Player()
{
	
}

void Player::Update()
{
	//回転行列
	MATRIX rotY = MGetRotY(rotation.y);


	//前
	if (CheckHitKey(KEY_INPUT_W))
	{
		//回転値に応じて加速する値
		VECTOR velocity = VTransform(VGet(0.0, 0.0, 1.5), rotY);
		//現在の座標に加速した値を加算
		position = VAdd(position, velocity);
	}
	//後ろ
	if (CheckHitKey(KEY_INPUT_S))
	{
		//回転値に応じて-加速する値
		VECTOR velocity = VTransform(VGet(0.0, 0.0, -1.5), rotY);
		//現在の座標に加速した値を加算
		position = VAdd(position, velocity);
	}
	//左
	if (CheckHitKey(KEY_INPUT_A))
	{
		//右旋回
		rotation.y -= 3.0*DX_PI_F / 180.0;
	}
	//右
	if (CheckHitKey(KEY_INPUT_D))
	{
		//左旋回
		rotation.y += 3.0*DX_PI_F / 180.0;
	}


	//VECTOR upper = VAdd(position, VGet(0, 1000, 0));
	VECTOR upper = VAdd(position, VGet(0, 10, 0));
	VECTOR lower = VAdd(position, VGet(0, -1000, 0));
	VECTOR hitposition;

	


	//地形との当たり判定
	Field* pField = GetScene()->FindGameObject<Field>();
	if (pField->CollisoinLine(&hitposition, upper, lower))
	{
		position = hitposition;
	}

	//球体を使った壁との当たり判定
	if (pField->CollisoinSphere(&hitposition,position))
	{
		position = hitposition;
	}

}

void Player::Draw()
{
	//移動行列
	MATRIX mTranslate = MGetTranslate(position);
	//Y軸の回転行列
	MATRIX mRotationY = MGetRotY(rotation.y);
	//回転してから移動
	MATRIX matrix = MMult(mRotationY, mTranslate);
	//MV1SetPosition(hModel, position);
	MV1SetMatrix(hModel, matrix);
	MV1DrawModel(hModel);



#if 1	//プレイヤーのデバッグ用
	DebugSetColor(255, 0, 255);
	DebugPrintf(0, 50, "自機の座標:X%d,Y%d,Z%d", mTranslate);
	DrawSphere3D(VAdd(position,VGet(0,10,0)), 10, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), false);
	Player* pPlayer = GetScene()->FindGameObject<Player>();
	
	DrawLine3D(position, VAdd(position, VGet(0, 10, 0)), GetColor(255, 0, 0));
	DrawLine3D(position, VAdd(position, VGet(0, -1000, 0)), GetColor(0, 0, 255));
#endif // 0

}
