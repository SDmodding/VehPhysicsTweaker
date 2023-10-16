#pragma once

namespace Hook
{
	namespace CarPhysicsDef
	{
		typedef void(__fastcall* m_tCarPhysicsDef)(UFG::CCarPhysicsDef*);
		m_tCarPhysicsDef m_oCarPhysicsDef;

		void __fastcall CarPhysicsDef(UFG::CCarPhysicsDef* p_CarPhysicsDef)
		{
			m_oCarPhysicsDef(p_CarPhysicsDef);
			if (!p_CarPhysicsDef)
				return;

			g_Configuration.Vehicle.Car.ApplyBase(p_CarPhysicsDef);
		}
	}
}