#include "pch.h"
#include "Pipeline.h"


Pipeline::Pipeline()
{
}

void Pipeline::Scale(float ScaleX, float ScaleY, float ScaleZ)
{
	m_scale.x = ScaleX;
	m_scale.y = ScaleY;
	m_scale.z = ScaleZ;

}

void Pipeline::WorldPos(float x, float y, float z)
{
	m_worldPos.x = x;
	m_worldPos.y = y;
	m_worldPos.z = z;
}

void Pipeline::Rotate(float RotateX, float RotateY, float RotateZ)
{
	m_rotateInfo.x = ToRadian(RotateX);
	m_rotateInfo.y = ToRadian(RotateY);
	m_rotateInfo.z = ToRadian(RotateZ);
}


const Matrix4f * Pipeline::GetTrans()
{
	Matrix4f ScaleTrans, RotateTrans, TranslationTrans;
	InitScaleTransform(ScaleTrans);
	InitRotateTransform(RotateTrans);
	InitTranslationTransform(TranslationTrans);
	m_transformation = TranslationTrans * RotateTrans * ScaleTrans;
	return &m_transformation;
}

void Pipeline::InitScaleTransform(Matrix4f &trans) {

	trans.m[0][0] = m_scale.x;	trans.m[0][1] = 0.0f;		trans.m[0][2] = 0.0f;		trans.m[0][3] = 0.0f;
	trans.m[1][0] = 0.0f;		trans.m[1][1] = m_scale.y;	trans.m[1][2] = 0.0f;		trans.m[1][3] = 0.0f;
	trans.m[2][0] = 0.0f;		trans.m[2][1] = 0.0f;		trans.m[2][2] = m_scale.z;	trans.m[2][3] = 0.0f;
	trans.m[3][0] = 0.0f;		trans.m[3][1] = 0.0f;		trans.m[3][2] = 0.0f;		trans.m[3][3] = 1.0f;
}

void Pipeline::InitRotateTransform(Matrix4f &trans) {
	trans.m[0][0] = cosf(m_rotateInfo.x);	trans.m[0][1] = -sinf(m_rotateInfo.x);	trans.m[0][2] = 0.0f;	trans.m[0][3] = 0.0f;
	trans.m[1][0] = sinf(m_rotateInfo.x);	trans.m[1][1] = cosf(m_rotateInfo.x);	trans.m[1][2] = 0.0f;	trans.m[1][3] = 0.0f;
	trans.m[2][0] = 0.0f;					trans.m[2][1] = 0.0f;					trans.m[2][2] = 1.0f;	trans.m[2][3] = 0.0f;
	trans.m[3][0] = 0.0f;					trans.m[3][1] = 0.0f;					trans.m[3][2] = 0.0f;	trans.m[3][3] = 1.0f;
}

void Pipeline::InitTranslationTransform(Matrix4f &trans) {
	trans.m[0][0] = 1.0f;	trans.m[0][1] = 0.0f;	trans.m[0][2] = 0.0f;	trans.m[0][3] = m_worldPos.x;
	trans.m[1][0] = 0.0f;	trans.m[1][1] = 1.0f;	trans.m[1][2] = 0.0f;	trans.m[1][3] = m_worldPos.y;
	trans.m[2][0] = 0.0f;	trans.m[2][1] = 0.0f;	trans.m[2][2] = 1.0f;	trans.m[2][3] = m_worldPos.z;
	trans.m[3][0] = 0.0f;	trans.m[3][1] = 0.0f;	trans.m[3][2] = 0.0f;	trans.m[3][3] = 1.0f;
}
