/*
* Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "InstanceScript.h"
#include "shadowfang_keep.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"

enum Texts
{
	YELL_AGGRO = 1,
	YELL_DEATH = 2,
};

enum Spells
{
	SPELL_VEIL_OF_SHADOW	= 17820,
	SPELL_CURSED_VEIL		= 93956,
};

enum Actions
{

};

enum Points
{

};

enum Events
{
	EVENT_VEIL_OF_SHADOW = 1,
	EVENT_CURSED_VEIL	 = 2,
    EVENT_SUMMON         = 3,
};

bool first  = true;
bool second = true;


class boss_baron_silverlaine : public CreatureScript
{
    public:
        boss_baron_silverlaine() : CreatureScript("baron_silverlaine") { }

        struct boss_baron_silverlaineAI : public BossAI
        {
            boss_baron_silverlaineAI(Creature* creature) : BossAI(creature, DATA_BARON_SILVERLAINE), Summons(me)
            {
                first  = true;
                second = true;
            }

            SummonList Summons;

            void Reset()
            {
                _Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(YELL_AGGRO);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
				events.ScheduleEvent(EVENT_VEIL_OF_SHADOW, 10000);
                events.ScheduleEvent(EVENT_CURSED_VEIL, 20000);
                events.ScheduleEvent(EVENT_SUMMON, 500);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(YELL_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void JustSummoned(Creature* summon)
            {
                Summons.Summon(summon);
            }

            void KilledUnit(Unit* who)
            {

            }

            void EnterEvadeMode()
            {
                me->GetMotionMaster()->MoveTargetedHome();
                Summons.DespawnAll();
            }

            void DoAction(int32 action)
            {

            }

            void MovementInform(uint32 /*type*/, uint32 pointId)
            {

            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

				while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_VEIL_OF_SHADOW:	
							if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
								DoCast(target, SPELL_VEIL_OF_SHADOW, true);
                            }
                            events.ScheduleEvent(EVENT_VEIL_OF_SHADOW, 10000);
                            break;
                        
                        case EVENT_CURSED_VEIL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
								DoCast(target, SPELL_CURSED_VEIL, true);
                            }
                            events.ScheduleEvent(EVENT_CURSED_VEIL, 20000);
                            break;
                    
                        case EVENT_SUMMON:
                            if ((me->HealthBelowPct(70)) && (first == true))
                            {
                                switch(urand(0,3))
                                {
                                    case 0:
                                        me->SummonCreature(WOLF_MASTER_NANDOS,me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0,
                                            TEMPSUMMON_MANUAL_DESPAWN);
                                        first = false;
                                        break;
                                    case 1:
                                        me->SummonCreature(RAZORCLAW_THE_BUTCHER,me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0,
                                            TEMPSUMMON_MANUAL_DESPAWN);
                                        first = false;
                                        break;
                                    case 2:
                                        me->SummonCreature(RETHILGORE,me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0,
                                            TEMPSUMMON_MANUAL_DESPAWN);
                                        first = false;
                                        break;
                                    case 3:
                                        me->SummonCreature(ODO_THE_BLINDWATCHER,me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0,
                                            TEMPSUMMON_MANUAL_DESPAWN);
                                        first = false;
                                        break;
                                }
                            }
                            else if ((me->HealthBelowPct(35)) && (second == true))
                            {
                                switch(urand(0,3))
                                {
                                    case 0:
                                        me->SummonCreature(WOLF_MASTER_NANDOS,me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0,
                                            TEMPSUMMON_MANUAL_DESPAWN);
                                        second = false;
                                        first = false;
                                        break;
                                    case 1:
                                        me->SummonCreature(RAZORCLAW_THE_BUTCHER,me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0,
                                            TEMPSUMMON_MANUAL_DESPAWN);
                                        second = false;
                                        first = false;
                                        break;
                                    case 2:
                                        me->SummonCreature(RETHILGORE,me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0,
                                            TEMPSUMMON_MANUAL_DESPAWN);
                                        second = false;
                                        first = false;
                                        break;
                                    case 3:
                                        me->SummonCreature(ODO_THE_BLINDWATCHER,me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0,
                                            TEMPSUMMON_MANUAL_DESPAWN);
                                        second = false;
                                        first = false;
                                        break;
                                }
                            }
                            events.ScheduleEvent(EVENT_SUMMON, 500);
                            break;
                    }      
                }
                DoMeleeAttackIfReady();
            }
        };
        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_baron_silverlaineAI(creature);
        }
};

void AddSC_boss_baron_silverlaine()
{
    new boss_baron_silverlaine();
}