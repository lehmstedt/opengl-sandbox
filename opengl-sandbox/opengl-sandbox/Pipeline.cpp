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


const Matrix4f* Pipeline::GetTrans()
{
	Matrix4f ScaleTrans, RotateTrans, TranslationTrans, CameraTranslationTrans, CameraRotateTrans, PersProjTrans;

	ScaleTrans.InitScaleTransform(m_scale.x, m_scale.y, m_scale.z);
	RotateTrans.InitRotateTransform(m_rotateInfo.x, m_rotateInfo.y, m_rotateInfo.z);
	TranslationTrans.InitTranslationTransform(m_worldPos.x, m_worldPos.y, m_worldPos.z);
	CameraTranslationTrans.InitTranslationTransform(-m_camera.Pos.x, -m_camera.Pos.y, -m_camera.Pos.z);
	CameraRotateTrans.InitCameraTransform(m_camera.Target, m_camera.Up);
	PersProjTrans.InitPersProjTransform(m_persProj.FOV, m_persProj.Width, m_persProj.Height, m_persProj.zNear, m_persProj.zFar);

	m_transformation = PersProjTrans * CameraRotateTrans * CameraTranslationTrans * TranslationTrans * RotateTrans * ScaleTrans;
	return &m_transformation;
}



void Pipeline::SetPerspectiveProj(float zNear, float width, float height, float fov, float zFar)
{
	m_persProj.zNear = zNear;
	m_persProj.Width = width;
	m_persProj.Height = height;
	m_persProj.FOV = fov;
	m_persProj.zFar = zFar;
}

void Pipeline::SetCamera(Vector3f pos, Vector3f target, Vector3f up)
{
	m_camera.Pos = pos;
	m_camera.Target = target;
	m_camera.Up = up;
}
