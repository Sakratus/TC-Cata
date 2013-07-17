/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Instance_Shadowfang_Keep
SD%Complete: 90
SDComment:
SDCategory: Shadowfang Keep
EndScriptData */

#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "lost_city_of_the_tolvir.h"
#include "TemporarySummon.h"

#define MAX_ENCOUNTER              4

enum eEnums
{
    SAY_BOSS_DIE_AD         = 4,
    SAY_BOSS_DIE_AS         = 3,
    SAY_ARCHMAGE            = 0,

    NPC_GENERAL_HUSAM           = 44577,
	NPC_HIGH_PROPETH_BARIM      = 43612,
    NPC_LOCKMAW                 = 43614,
    NPC_FRENZIED_CROCOLISK      = 44892,
    NPC_AUGH                    = 49045,

    GO_COURTYARD_DOOR       = 18895,                        //door to open when talking to NPC's
    GO_SORCERER_DOOR        = 18972,                        //door to open when Fenrus the Devourer
    GO_ARUGAL_DOOR          = 18971,                        //door to open when Wolf Master Nandos

    SPELL_ASHCROMBE_TELEPORT    = 15742
};

const Position SpawnLocation[] =
{
    {-148.199f, 2165.647f, 128.448f, 1.026f},
    {-153.110f, 2168.620f, 128.448f, 1.026f},
    {-145.905f, 2180.520f, 128.448f, 4.183f},
    {-140.794f, 2178.037f, 128.448f, 4.090f},
    {-138.640f, 2170.159f, 136.577f, 2.737f}
};
class instance_lost_city_of_the_tolvir : public InstanceMapScript
{
public:
    instance_lost_city_of_the_tolvir() : InstanceMapScript("instance_lost_city_of_the_tolvir", 755) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_lost_city_of_the_tolvir_InstanceMapScript(map);
    }

    struct instance_lost_city_of_the_tolvir_InstanceMapScript : public InstanceScript
    {
        instance_lost_city_of_the_tolvir_InstanceMapScript(Map* map) : InstanceScript(map) {}

        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string str_data;

        uint64 uiGeneralHusamGUID;
        uint64 uiHighPropethBarimGUID;
        uint64 uiLockmawGUID;
        uint64 uiAughGUID;

        uint64 SnowWeatherGUID;
        uint64 KokoGUID;

        uint64 DoorCourtyardGUID;
        uint64 DoorSorcererGUID;
        uint64 DoorArugalGUID;

        uint8 uiPhase;
        uint16 uiTimer;

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            uiGeneralHusamGUID = 0;
            uiHighPropethBarimGUID = 0;
            uiLockmawGUID = 0;
            uiAughGUID = 0;

            KokoGUID        = 0;
            SnowWeatherGUID = 0;

            DoorCourtyardGUID = 0;
            DoorSorcererGUID = 0;
            DoorArugalGUID = 0;

            uiPhase = 0;
            uiTimer = 0;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_GENERAL_HUSAM: uiGeneralHusamGUID = creature->GetGUID(); break;
                case NPC_HIGH_PROPETH_BARIM: uiHighPropethBarimGUID = creature->GetGUID(); break;
                case NPC_LOCKMAW: uiLockmawGUID = creature->GetGUID(); break;
                case NPC_AUGH: uiAughGUID = creature->GetGUID(); break;

            }
        }

        void OnGameObjectCreate(GameObject* gameObject)
        {
            switch (gameObject->GetEntry())
            {
                  case SNOW_WEATHER:
                        SnowWeatherGUID = gameObject->GetGUID();
                        break;

                  case KOKO:
                        KokoGUID = gameObject->GetGUID();
                        break;

            }
        }

        void OnCreatureDeath()
        {

        }

        void DoSpeech()
        {

        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case TYPE_LOCKMAW:
                    if (data == DONE)
                    {
                        
                        if (GameObject* gameObjectt = instance->GetGameObject(KokoGUID))
                            gameObjectt->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);

                        if (GameObject* gameObject = instance->GetGameObject(SnowWeatherGUID))
                            gameObject->SetRespawnTime(gameObject->GetRespawnDelay());

                     
                    } 
                    break;

                case TYPE_AUGH:
                    break;
            }

            if (data == DONE)
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << m_auiEncounter[0] << ' ' << m_auiEncounter[1] << ' ' << m_auiEncounter[2] << ' ' << m_auiEncounter[3];

                str_data = saveStream.str();

                SaveToDB();
                OUT_SAVE_INST_DATA_COMPLETE;
            }
        }

        uint32 GetData(uint32 type) const
        {
            switch (type)
            {
                case TYPE_AUGH:
                    return uiAughGUID;
            }
            return 0;
        }

        std::string GetSaveData()
        {
            return str_data;
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            std::istringstream loadStream(in);
            loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3];

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            {
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;
            }

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        void Update(uint32 uiDiff)
        {
            
        }
    };

};

void AddSC_instance_lost_city_of_the_tolvir()
{
    new instance_lost_city_of_the_tolvir();
}
