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
#include "lost_city_of_the_tolvir.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"

enum Texts
{
	YELL_AGGRO      = 1,
	YELL_DEATH      = 2,
    YELL_SHOCKWAVE  = 3,
};

enum Spells
{
	SPELL_SHOCKWAVE     	= 83445,
	SPELL_HAMMER_FIST		= 83655,
    SPELL_BAD_INTENTIONS    = 83113,
    SPELL_MYSTIC_TRAP       = 83171,
    SPELL_DETONATE_TRAPS    = 91263,
};

enum Actions
{

};

enum Points
{

};

enum Events
{
	EVENT_SHOCKWAVE          = 1,
	EVENT_BAD_INTENTIONS	 = 2,
    EVENT_HAMMER_FIST        = 3,
};



class boss_general_husam : public CreatureScript
{
    public:
        boss_general_husam() : CreatureScript("general_husam") { }

        struct boss_general_husamAI : public BossAI
        {
            boss_general_husamAI(Creature* creature) : BossAI(creature, DATA_GENERAL_HUSAM)
            {

            }

            void Reset()
            {
            if (instance && (instance->GetData(DATA_GENERAL_HUSAM) != DONE))
                instance->SetData(DATA_GENERAL_HUSAM, FAIL);
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (instance)
                instance->SetData(DATA_GENERAL_HUSAM, IN_PROGRESS);
                me->SetInCombatWithZone();
                _EnterCombat();
                Talk(YELL_AGGRO);
              //  instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_SHOCKWAVE, 5000);
                events.ScheduleEvent(EVENT_BAD_INTENTIONS, 11000);
               // events.ScheduleEvent(EVENT_HAMMER_FIST, 2000);
            }

            void JustDied(Unit* /*killer*/)
            {
                            if (instance)
                instance->SetData(DATA_GENERAL_HUSAM, DONE);
                Talk(YELL_DEATH);
             //   instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void KilledUnit(Unit* who)
            {

            }

            void EnterEvadeMode()
            {
                me->GetMotionMaster()->MoveTargetedHome();
                
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
                        case EVENT_SHOCKWAVE:	
							if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                DoCast(me, SPELL_SHOCKWAVE);
                                Talk(YELL_SHOCKWAVE);
                                    //target, SPELL_SHOCKWAVE, true);
                            }
                            events.ScheduleEvent(EVENT_SHOCKWAVE, 10000);
                            break;

                        case EVENT_BAD_INTENTIONS:	
							if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
								DoCast(target, SPELL_BAD_INTENTIONS, true);
                            }
                            events.ScheduleEvent(EVENT_BAD_INTENTIONS, 6000);
                            break;

                        case EVENT_HAMMER_FIST:	
							if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
								DoCast(target, SPELL_HAMMER_FIST, true);
                            }
                            events.ScheduleEvent(EVENT_HAMMER_FIST, 2000);
                            break;

                    }
                }
                DoMeleeAttackIfReady();
            }
        };
        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_general_husamAI(creature);
        }
};

void AddSC_boss_general_husam()
{
    new boss_general_husam();
}