#pragma once

namespace Hook
{
	namespace BoatPhysicsDef
	{
		typedef void(__fastcall* m_tBoatPhysicsDef)(UFG::CBoatPhysicsDef*);
		m_tBoatPhysicsDef m_oBoatPhysicsDef;

		void __fastcall BoatPhysicsDef(UFG::CBoatPhysicsDef* p_BoatPhysicsDef)
		{
			m_oBoatPhysicsDef(p_BoatPhysicsDef);
			if (!p_BoatPhysicsDef)
				return;

			g_Configuration.Vehicle.Boat.ApplyBase(p_BoatPhysicsDef);
		}
	}
}