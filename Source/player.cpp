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

	//プレイヤーの初期位置
	position = VGet(-150, -100, 150);
	rotation = VGet(0, 0, 0);

	
}

	
Player::~Player()
{
}


void Player::Update()
{

	//回転行列
	MATRIX rotY = MGetRotY(rotation.y);

	//移動する前の座標を保存
	VECTOR tempPos = position;
	
	//前進
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
		//左旋回
		rotation.y -= 3.0*DX_PI_F / 180.0;
	}
	//右
	if (CheckHitKey(KEY_INPUT_D))
	{
		//右旋回
		rotation.y += 3.0*DX_PI_F / 180.0;
	}


	//プレイヤーの上側のレイの範囲
	VECTOR upper = VAdd(position, VGet(0, 50, 0));
	//プレイヤーの下側のレイの範囲
	VECTOR lower = VAdd(position, VGet(0, -50, 0));
	//レイが当たった時の座標
	VECTOR hitposition;

	


	//地形とレイの当たり判定
	Field* pField = GetScene()->FindGameObject<Field>();
	if (pField->CollisoinLine(&hitposition, upper, lower))
	{
		//レイと地形が当たったところにプレイヤーを移動
		position = hitposition;
	}


	//球体を使った壁との当たり判定
	if (pField->CollisoinSphere(&hitposition,position))
	{

#if 0	//デバッグ表示
		DebugSetColor(255, 0, 0);
		DebugPrintf(0, 10, "壁");
#endif // 0
		//現在の座標に前の座標を代入
		position = tempPos;
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
	MV1SetMatrix(hModel, matrix);
	MV1DrawModel(hModel);



#if 0	//プレイヤーのデバッグ用
	DebugSetColor(255, 0, 255);
	DebugPrintf(0, 50, "自機の座標:X%f,Y%f,Z%f", position.x,position.y,position.z);
	DrawSphere3D(VAdd(position,VGet(0,10,0)), 5, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), false);
	
	DrawLine3D(position, VAdd(position, VGet(0, 50, 0)), GetColor(255, 0, 0));
	DrawLine3D(position, VAdd(position, VGet(0, -50, 0)), GetColor(0, 0, 255));
#endif // 0

}
