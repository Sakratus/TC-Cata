/*

########
# TODO #
########

- Fix 'spell_script_missile_barrage' - effect doesn't work properly, shows an "explosion"
instead of flying rockets

*/

// #############################
// # 25841 - Strike From Above #
// #############################

static Position PosList[] =
{
	{-5716.703f, -1020.835f, 394.835f}, // 0  Northern point
	{-5810.872f, -960.414f,  393.454f}, // 1  Southern point

	{-5749.251f, -985.765f,  410.0f},   // 2  Spawn heli #1
	{-5754.891f, -991.146f,  410.0f},   // 3  Spawn heli #2

	{-5698.512f, -1024.870f, 397.938f}, // 4  North fire #1
	{-5691.642f, -1030.565f, 399.301f}, // 5  North fire #2
	{-5711.657f, -1034.421f, 401.402f}, // 6  North fire #3
	{-5705.522f, -1040.662f, 398.759f}, // 7  North fire #4

	{-5822.173f, -952.001f, 394.783f},  // 8  South fire #1
	{-5829.234f, -948.993f, 393.999f},  // 9  South fire #2
	{-5808.042f, -943.723f, 400.140f},  // 10 South fire #3
	{-5807.288f, -938.485f, 396.597f},  // 11 South fire #4
};

static Position WaypointHeliA[] =
{
	{-5706.567f, -1020.474f, 410.0f, 5.829f}, // 0 North Heli #1, WP #1
	{-5677.614f, -1002.069f, 410.0f, 0.886f}, // 1 North Heli #1, WP #2
	{-5801.550f, -951.188f,  410.0f, 2.100f}, // 2 South Heli #1, WP #1
	{-5760.671f, -910.329f,  410.0f, 5.340f}, // 3 South Heli #1, WP #2
};

static Position WaypointHeliB[] =
{
	{-5717.173f, -1025.738f, 410.0f, 5.213f}, // 0 North Heli #2, WP #1
	{-5700.125f, -1073.253f, 410.0f, 5.272f}, // 1 North Heli #2, WP #2	
	{-5815.524f, -955.940f,  410.0f, 2.670f}, // 2 South Heli #2, WP #1
	{-5854.934f, -976.068f,  410.0f, 3.671f}, // 3 South Heli #2, WP #2
};

enum Assets
{
	QUEST_STRIKE = 25841,
	NPC_NORTH = 41372,
	NPC_SOUTH = 41373,
	NPC_HELI = 41382,
	NPC_BOMB_BUNNY = 41375,
	OBJECT_FIRE = 182090,
	SPELL_MISSILE_BARRAGE = 77477
};

enum Events
{
	EVENT_HELI_N_WP1 = 1,
	EVENT_HELI_S_WP1,
	EVENT_HELI_SHOOT,
	EVENT_HELI_N_FIRE,
	EVENT_HELI_S_FIRE,
	EVENT_HELI_N_WP2,
	EVENT_HELI_S_WP2,
	EVENT_HELI_REMOVE
};

class npc_covert_ops_machine : public CreatureScript
{
public:
	npc_covert_ops_machine() : CreatureScript("npc_covert_ops_machine") { }	

	struct npc_covert_ops_machineAI : public ScriptedAI
	{
		npc_covert_ops_machineAI(Creature* creature) : ScriptedAI(creature) { }

		void IsSummonedBy(Unit* u)
		{
			player = u->ToPlayer();
			if (!wplist)
				wplist = WaypointHeliA; // protection against racing condition, probably not needed
			HeliSpawned();
		}

		void HeliSpawned()
		{
			events.Reset();
			me->SetReactState(REACT_PASSIVE);

			if (player->IsInDist(&PosList[0], 10.0f))
			{
				player->KilledMonsterCredit(NPC_NORTH);
				events.ScheduleEvent(EVENT_HELI_N_WP1, 150);
				events.ScheduleEvent(EVENT_HELI_SHOOT, 8000);
				events.ScheduleEvent(EVENT_HELI_SHOOT, 8350);
				events.ScheduleEvent(EVENT_HELI_N_FIRE, 8400);
				events.ScheduleEvent(EVENT_HELI_SHOOT, 8700);
				events.ScheduleEvent(EVENT_HELI_SHOOT, 9050);
				events.ScheduleEvent(EVENT_HELI_N_WP2, 12100);
				events.ScheduleEvent(EVENT_HELI_REMOVE, 16000);
			}
			else if (player->IsInDist(&PosList[1], 10.0f))
			{
				player->KilledMonsterCredit(NPC_SOUTH);
				events.ScheduleEvent(EVENT_HELI_S_WP1, 150);
				events.ScheduleEvent(EVENT_HELI_SHOOT, 9500);
				events.ScheduleEvent(EVENT_HELI_SHOOT, 9850);
				events.ScheduleEvent(EVENT_HELI_S_FIRE, 9900);
				events.ScheduleEvent(EVENT_HELI_SHOOT, 10100);
				events.ScheduleEvent(EVENT_HELI_SHOOT, 10450);
				events.ScheduleEvent(EVENT_HELI_S_WP2, 13700);
				events.ScheduleEvent(EVENT_HELI_REMOVE, 17500);
			}
		}

		void SetGUID(uint64 /*guid*/, int32 id)
		{
			switch(id)
			{
			case 1:
				wplist = WaypointHeliA;
				break;
			case 2:
				wplist = WaypointHeliB;
				break;
			}
		}

		void UpdateAI(uint32 diff)
		{
			events.Update(diff);

			while (uint32 event = events.ExecuteEvent())
			{
				switch(event)
				{
				case EVENT_HELI_N_WP1:
					me->GetMotionMaster()->MovePoint(0, wplist[0]);
					break;
				case EVENT_HELI_S_WP1:
					me->GetMotionMaster()->MovePoint(0, wplist[2]);
					break;
				case EVENT_HELI_SHOOT:
					me->GetAI()->DoCast(me->FindNearestCreature(NPC_BOMB_BUNNY, 100.0f), SPELL_MISSILE_BARRAGE);
					break;
				case EVENT_HELI_N_FIRE:
					player->SummonGameObject(OBJECT_FIRE, PosList[4].GetPositionX(), PosList[4].GetPositionY(),
						PosList[4].GetPositionZ(), 0, 0, 0, 0, 0, 120);
					player->SummonGameObject(OBJECT_FIRE, PosList[5].GetPositionX(), PosList[5].GetPositionY(),
						PosList[5].GetPositionZ(), 0, 0, 0, 0, 0, 120);
					player->SummonGameObject(OBJECT_FIRE, PosList[6].GetPositionX(), PosList[6].GetPositionY(),
						PosList[6].GetPositionZ(), 0, 0, 0, 0, 0, 120);
					player->SummonGameObject(OBJECT_FIRE, PosList[7].GetPositionX(), PosList[7].GetPositionY(),
						PosList[7].GetPositionZ(), 0, 0, 0, 0, 0, 120);
					break;
				case EVENT_HELI_S_FIRE:
					player->SummonGameObject(OBJECT_FIRE, PosList[8].GetPositionX(), PosList[8].GetPositionY(),
						PosList[8].GetPositionZ(), 0, 0, 0, 0, 0, 120);
					player->SummonGameObject(OBJECT_FIRE, PosList[9].GetPositionX(), PosList[9].GetPositionY(),
						PosList[9].GetPositionZ(), 0, 0, 0, 0, 0, 120);
					player->SummonGameObject(OBJECT_FIRE, PosList[10].GetPositionX(), PosList[10].GetPositionY(),
						PosList[10].GetPositionZ(), 0, 0, 0, 0, 0, 120);
					player->SummonGameObject(OBJECT_FIRE, PosList[11].GetPositionX(), PosList[11].GetPositionY(),
						PosList[11].GetPositionZ(), 0, 0, 0, 0, 0, 120);
					break;
				case EVENT_HELI_N_WP2:						
					me->GetMotionMaster()->MovePoint(0, wplist[1]);
					break;
				case EVENT_HELI_S_WP2:						
					me->GetMotionMaster()->MovePoint(0, wplist[3]);
					break;
				case EVENT_HELI_REMOVE:
					me->DespawnOrUnsummon();
					break;
				}
			}
		}

	private:
		EventMap events;
		Player* player;
		Position* wplist;
	};

	CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_covert_ops_machineAI(creature);
	}
};

// 77477 - Missile Barrage
class spell_script_missile_barrage : public SpellScriptLoader
{
public:
	spell_script_missile_barrage() : SpellScriptLoader("spell_script_missile_barrage") { }

	class spell_script_missile_barrageSpellScript : public SpellScript
	{
		PrepareSpellScript(spell_script_missile_barrageSpellScript);

		void HandleDummyHitTarget(SpellEffIndex /*effIndex*/)
		{
			//if (Unit* target = GetHitUnit())
			//target->CastSpell(target, SPELL_MISSILE_BARRAGE);
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(spell_script_missile_barrageSpellScript::HandleDummyHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_script_missile_barrageSpellScript();
	}
};

// 77488 - Signal Flare
class spell_strike_from_above_signal_flare : public SpellScriptLoader
{
public:
	spell_strike_from_above_signal_flare() : SpellScriptLoader("spell_strike_from_above_signal_flare") { }

	class spell_strike_from_above_signal_flareSpellScript : public SpellScript
	{
		PrepareSpellScript(spell_strike_from_above_signal_flareSpellScript);
		Player* player;

		bool Load()
		{
			player = GetCaster()->ToPlayer();
			return true;
		}

		SpellCastResult CheckRequirement()
		{
			if (player->IsInDist(&PosList[0], 10.0f) && player->GetReqKillOrCastCurrentCount(QUEST_STRIKE, NPC_NORTH) == 0)
				return SPELL_CAST_OK;
			else if (player->IsInDist(&PosList[1], 10.0f) && player->GetReqKillOrCastCurrentCount(QUEST_STRIKE, NPC_SOUTH) == 0)
				return SPELL_CAST_OK;
			else
				return SPELL_FAILED_INCORRECT_AREA;
		}

		void HandleAfterCast()
		{
			if (Unit* heli1 = player->SummonCreature(NPC_HELI, PosList[2]))
				heli1->GetAI()->SetGUID(heli1->GetGUID(), 1);

			if (Unit* heli2 = player->SummonCreature(NPC_HELI, PosList[3]))
				heli2->GetAI()->SetGUID(heli2->GetGUID(), 2);
		}

		void Register()
		{
			OnCheckCast += SpellCheckCastFn(spell_strike_from_above_signal_flareSpellScript::CheckRequirement);
			AfterCast += SpellCastFn(spell_strike_from_above_signal_flareSpellScript::HandleAfterCast);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_strike_from_above_signal_flareSpellScript();
	}
};


//npc Rockjaw Scavenger
class npc_rockjaw_scavenger : public CreatureScript
{
    public:
    	enum Spells
		{
    		SPELL_ONE                                   = 69897,
		};
		
        npc_rockjaw_scavenger()
            : CreatureScript("npc_rockjaw_scavenger")
        {
        }
        struct npc_rockjaw_scavengerAI : public ScriptedAI
        {
            npc_rockjaw_scavengerAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 m_uiSayTimer;                                    // Timer for random chat
            uint32 m_uiSpell1Timer;                                 // Timer for spell 1 when in combat

            void Reset()
            {
                m_uiSpell1Timer = 0;                             
            }
            void EnterCombat(Unit* who)
            {
//                Talk( SAY_AGGRO, who->GetGUID());
            }
            void EnterEvadeMode()
            {
//                Talk(SAY_EVADE);
            }
            void UpdateAI(uint32 uiDiff)
            {
                if (!me->GetVictim())
                {
/*                    //Random Say timer
                    if (m_uiSayTimer <= uiDiff)
                    {
                        //Random switch between 5 outcomes
                        Talk(SAY_AGGRO);

                        m_uiSayTimer = 45000;                      //Say something again in 45 seconds
                    }
                    else
                        m_uiSayTimer -= uiDiff;
*/
                }
                if (!UpdateVictim())
                    return;
                    
                if (m_uiSpell1Timer <= uiDiff)
                {                 
                    DoCast(me->GetVictim(), SPELL_ONE);
                    m_uiSpell1Timer = 2000;
                }
                else
                    m_uiSpell1Timer -= uiDiff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_rockjaw_scavengerAI(creature);
        }
};

void AddSC_dun_morogh()
{
	new spell_strike_from_above_signal_flare();
	new spell_script_missile_barrage();
	new npc_covert_ops_machine();
    new npc_rockjaw_scavenger();	
}