#include "pch.h"
#include "Camera.h"


Camera::Camera()
{
}

Camera::Camera(const Vector3f & Pos, const Vector3f & Target, const Vector3f & Up)
{
	m_pos = Pos;
	m_target = Target;
	m_up = Up;
}

bool Camera::OnKeyboard(int Key)
{
	bool Ret = false;

	switch (Key) {

	case GLUT_KEY_UP:
	{
		m_pos += (m_target * StepSize);
		Ret = true;
	}
	break;

	case GLUT_KEY_DOWN:
	{
		m_pos -= (m_target * StepSize);
		Ret = true;
	}
	break;

	case GLUT_KEY_LEFT:
	{
		Vector3f Left = m_target.Cross(m_up);
		Left.Normalize();
		Left *= StepSize;
		m_pos += Left;
		Ret = true;
	}
	break;

	case GLUT_KEY_RIGHT:
	{
		Vector3f Right = m_up.Cross(m_target);
		Right.Normalize();
		Right *= StepSize;
		m_pos += Right;
		Ret = true;
	}
	break;
	}

	return Ret;
}

const Vector3f & Camera::GetPos() const
{
	return m_pos;
}

const Vector3f & Camera::GetTarget() const
{
	return m_target;
}

const Vector3f & Camera::GetUp() const
{
	return m_up;
}

