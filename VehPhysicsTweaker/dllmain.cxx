#include ".Includes.hxx"

namespace Hooks
{
    void AddHook(uintptr_t p_Function, void* p_Hook, void** p_Original = nullptr)
    {
        MH_CreateHook(reinterpret_cast<void*>(p_Function), p_Hook, p_Original);
        MH_EnableHook(reinterpret_cast<void*>(p_Function));
    }

    void Initialize()
    {
        MH_Initialize();

        AddHook(UFG_RVA(0x447CC0), Hook::BikePhysicsDef::BikePhysicsDef, (void**)&Hook::BikePhysicsDef::m_oBikePhysicsDef);
        AddHook(UFG_RVA(0x447CF0), Hook::BoatPhysicsDef::BoatPhysicsDef, (void**)&Hook::BoatPhysicsDef::m_oBoatPhysicsDef);
        AddHook(UFG_RVA(0x447D40), Hook::CarPhysicsDef::CarPhysicsDef, (void**)&Hook::CarPhysicsDef::m_oCarPhysicsDef);
    }
}

namespace Module
{
    void Initialize(HMODULE p_Module)
    {
        std::string m_ModuleDir(MAX_PATH, '\0');
        {
            GetModuleFileNameA(p_Module, &m_ModuleDir[0], MAX_PATH);
            m_ModuleDir = m_ModuleDir.substr(0, m_ModuleDir.find_last_of("/\\"));
        }

        g_Configuration.Initialize(m_ModuleDir + "\\VehPhysicsTweaker.ini");

        Hooks::Initialize();
    }
}

int __stdcall DllMain(HMODULE p_Module, DWORD p_Reason, void* p_Reserved)
{
    if (p_Reason == DLL_PROCESS_ATTACH)
    {
        if (!SDK::Utils::IsValidExecutable())
        {
            CMsgBox::ShowError("This is not valid executable.\nPlease visit: https://github.com/SDmodding \nAnd check README.md");
            return 0;
        }

        DisableThreadLibraryCalls(p_Module);
        Module::Initialize(p_Module);
    }

    return 1;
}