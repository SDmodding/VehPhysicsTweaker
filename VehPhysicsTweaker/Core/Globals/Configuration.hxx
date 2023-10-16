#pragma once

class CConfiguration
{
public:
	struct Vehicle_t
	{
		struct Base_t
		{
			bool m_DisablePitchStability : 1;
			bool m_DisableRollStability : 1;

			void ApplyBase(UFG::CBaseVehiclePhysicsDef* p_VehiclePhysicsDef)
			{
				if (m_DisablePitchStability)
					p_VehiclePhysicsDef->pitchStability = 0.f;

				if (m_DisableRollStability)
					p_VehiclePhysicsDef->rollStability = 0.f;
			}
		};
		Base_t Car;
		Base_t Bike;
		Base_t Boat;
	};
	Vehicle_t Vehicle;

	void Initialize(std::string p_FilePath)
	{
		CSimpleIniA m_INI;
		if (m_INI.LoadFile(&p_FilePath[0]) != SI_OK)
			return; // Oh no, it failed...

		// Vehicle
		{
			long m_DisablePitchStability = m_INI.GetLongValue("Vehicle", "DisablePitchStability");
			{
				Vehicle.Car.m_DisablePitchStability		= (m_DisablePitchStability & 1);
				Vehicle.Bike.m_DisablePitchStability	= (m_DisablePitchStability & 2);
				Vehicle.Boat.m_DisablePitchStability	= (m_DisablePitchStability & 4);
			}
			
			long m_DisableRollStability = m_INI.GetLongValue("Vehicle", "DisableRollStability");
			{
				Vehicle.Car.m_DisableRollStability		= (m_DisableRollStability & 1);
				Vehicle.Bike.m_DisableRollStability		= (m_DisableRollStability & 2);
				Vehicle.Boat.m_DisableRollStability		= (m_DisableRollStability & 4);
			}
		}
	}
};
CConfiguration g_Configuration;