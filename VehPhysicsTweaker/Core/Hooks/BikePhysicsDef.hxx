#pragma once

namespace Hook
{
	namespace BikePhysicsDef
	{
		typedef void(__fastcall* m_tBikePhysicsDef)(UFG::CBikePhysicsDef*);
		m_tBikePhysicsDef m_oBikePhysicsDef;

		void __fastcall BikePhysicsDef(UFG::CBikePhysicsDef* p_BikePhysicsDef)
		{
			m_oBikePhysicsDef(p_BikePhysicsDef);
			if (!p_BikePhysicsDef)
				return;

			g_Configuration.Vehicle.Bike.ApplyBase(p_BikePhysicsDef);
		}
	}
}