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
	SAY_AGGRO                = 1,
	SAY_GOES_TO_LOCKMAW      = 2,
    SAY_WHIRLWIND            = 3,
    SAY_LOCKMAW_DIE_FIRST    = 4,
    SAY_LOCKMAW_DIE_SECOND    = 5,
};

enum Spells
{
	SPELL_VISCOUS_POISON    = 81630,
	SPELL_DUST_FLAIL		= 81644,
    SPELL_VENOMOUS_RAGE     = 81706,
    SPELL_SCENT_OF_BLOOD    = 81690,

    SPELL_VICIOUS_BITE      = 81677,
    
    SPELL_PARALYTIC_BLOW_DART       = 84799,
    SPELL_WHIRLWIND                 = 91408,
    SPELL_SMOKE_BOMB                = 84768,
    SPELL_FRENZY                    = 91415,
    SPELl_DRAGONS_BREATH            = 83776,
};

enum Actions
{

};

enum Points
{

};

enum Events
{
	EVENT_VISCOUS_POISON            = 1,
	EVENT_DUST_FLAIL	            = 2,
    EVENT_VENOMOUS_RAGE             = 3,
    EVENT_SCENT_OF_BLOOD            = 4,
    EVENT_FRENZIED_CROCOLISK_SUMM   = 5,
    EVENT_VICIOUS_BITE              = 6,
    EVENT_SPAWN_AUGH                = 7,

    EVENT_CHANGE_AGGRO              = 8,

    EVENT_PARALYTIC_BLOW_DART       = 9,
    EVENT_WHIRLWIND                 = 10,
    EVENT_SMOKE_BOMB                = 11,
    EVENT_FRENZY                    = 12,
    EVENT_DRAGONS_BREATH            = 13,
    EVENT_STOP                      = 14,
    EVENT_CHANGE_TARGET             = 15,
};

const Position SpawnPointGuardian[4] =
{
    { -10988.452148f, -1659.438843f, 0.317107f, 2.478930f },
    { -11053.028320f, -1593.715088f, 0.757452f, 5.488301f },
    { -11074.0f     , -1621.723f   , 0.672504f, 6.002732f },
    { -11063.527344f, -1683.711914f, 0.904222f, 1.608433f },
};

bool phase_one = true;
uint8 u;

class augh : public CreatureScript
{
    public:
        augh() : CreatureScript("augh") { }

        struct aughAI : public BossAI
        {
            aughAI(Creature* creature) : BossAI(creature, DATA_AUGH)
            {

            }

            void Reset()
            {
                instance->SetData(TYPE_AUGH, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/)
            {
                me->SetInCombatWithZone();
                events.ScheduleEvent(EVENT_WHIRLWIND, 5000);
                events.ScheduleEvent(EVENT_STOP, 100);
                instance->SetData(TYPE_AUGH, IN_PROGRESS);
            }


            void JustDied(Unit* /*killer*/)
            {

            }

            void KilledUnit(Unit* who)
            {

            }

            void JustSummoned(Creature* summon)
            {

            }

            void EnterEvadeMode()
            {
                me->DespawnOrUnsummon(100);
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
                if(phase_one)
                {
				    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_STOP:
                                SetCombatMovement(false);
                                me->GetMotionMaster()->MovementExpired();
                                Talk(SAY_GOES_TO_LOCKMAW);
                                break;
                                
                            case EVENT_WHIRLWIND:
                                DoCast(SPELL_WHIRLWIND);
                                u = urand(1,4);
                                if(Unit * target = SelectTarget(SELECT_TARGET_RANDOM))
                                {  
                                    Talk(SAY_WHIRLWIND);
                                    SetCombatMovement(true);
                                    me->GetMotionMaster()->Clear();
                                    me->GetMotionMaster()->MovePoint(1, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation());
                                    events.ScheduleEvent(EVENT_CHANGE_TARGET, 4000);
                                    events.ScheduleEvent(EVENT_WHIRLWIND, 25000);
                                }
                                break;

                            case EVENT_CHANGE_TARGET:
                                if(Unit * target = SelectTarget(SELECT_TARGET_RANDOM))
                                {  
                                    me->GetMotionMaster()->Clear();
                                    me->GetMotionMaster()->MovePoint(1, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation());
                                    events.ScheduleEvent(EVENT_STOP, 6000);
                                }
                                break;

                        /*    case koko:
                                me->GetMotionMaster()->Clear();
                                    me->GetMotionMaster()->MovePoint(1, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation());
                        */}
                    }
                }
                else
                {
                    bool one = true;
                    if(one)
                    {

                    //if (Creature * Augh = ObjectAccessor::GetCreature(*me, instance->GetData64(TYPE_AUGH)))

                    me->GetMotionMaster()->Clear();
                    events.ScheduleEvent(EVENT_CHANGE_TARGET, 40000000);
                    me->GetMotionMaster()->MovePoint(2, -11067.6250f, -1665.902832f, 0.745541f, 0.752508f);
                    one = false;
                    }
                    DoMeleeAttackIfReady();
                }
            }
        };
        CreatureAI* GetAI(Creature* creature) const
        {
            return new aughAI(creature);
        }
};

class frenzied_crocolisk : public CreatureScript
{
    public:
        frenzied_crocolisk() : CreatureScript("frenzied_crocolisk") { }

        struct frenzied_crocoliskAI : public BossAI
        {
            frenzied_crocoliskAI(Creature* creature) : BossAI(creature, DATA_FRENZIED_CROCOLISK)
            {

            }

            void Reset()
            {

            }

            void EnterCombat(Unit* /*who*/)
            {
                me->SetInCombatWithZone();
                events.ScheduleEvent(EVENT_VICIOUS_BITE, 800);
                events.ScheduleEvent(EVENT_CHANGE_AGGRO, 1000);
            }


            void JustDied(Unit* /*killer*/)
            {

            }

            void KilledUnit(Unit* who)
            {

            }

            void JustSummoned(Creature* summon)
            {

            }

            void EnterEvadeMode()
            {
                me->DespawnOrUnsummon(100);
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
                        case EVENT_VICIOUS_BITE:
                            DoCast(SPELL_VICIOUS_BITE);
                            events.ScheduleEvent(EVENT_VICIOUS_BITE, 800);
                            break;

                        case EVENT_CHANGE_AGGRO:
                            if(Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, false, SPELL_SCENT_OF_BLOOD))
                            {
                                me->AddThreat(target, 500000.0f);
                            }

                    }
                }
            DoMeleeAttackIfReady();
            }
        };
        CreatureAI* GetAI(Creature* creature) const
        {
            return new frenzied_crocoliskAI(creature);
        }
};

class boss_lockmaw : public CreatureScript
{
    public:
        boss_lockmaw() : CreatureScript("lockmaw") { }

        struct boss_lockmawAI : public BossAI
        {
            boss_lockmawAI(Creature* creature) : BossAI(creature, DATA_LOCKMAW), Summons(me)
            {

            }

            SummonList Summons;

            void Reset()
            {
                if (instance)
                {
                    instance->SetData(TYPE_LOCKMAW, NOT_STARTED);
                }
            }
            void EnterCombat(Unit* /*who*/)
            {
                if (instance)
                instance->SetData(TYPE_LOCKMAW, IN_PROGRESS);
                me->SetInCombatWithZone();
                _EnterCombat();
                //events.ScheduleEvent(EVENT_VISCOUS_POISON, 1000);
                events.ScheduleEvent(EVENT_DUST_FLAIL, 10000);
                events.ScheduleEvent(EVENT_VENOMOUS_RAGE, 200);
                events.ScheduleEvent(EVENT_SCENT_OF_BLOOD, 20000);
                events.ScheduleEvent(EVENT_FRENZIED_CROCOLISK_SUMM, 10000);
                events.ScheduleEvent(EVENT_SPAWN_AUGH, 10000);
            }


            void JustDied(Unit* /*killer*/)
            {
                if (instance)
                    instance->SetData(TYPE_LOCKMAW, DONE);

                phase_one = false;

                if (Creature * Augh = ObjectAccessor::GetCreature(*me, instance->GetData64(TYPE_AUGH)))
                    Augh->GetMotionMaster()->MovePoint(-11067.6250f, -1665.902832f, 0.745541f, 0.752508f);
                    
                  /*  
                    me->SummonCreature(AUGH, -11067.6250f, -1665.902832f, 0.745541f, 0.752508f,TEMPSUMMON_MANUAL_DESPAWN))
                {
                    DoZoneInCombat(Augh);
                }*/
            }

            void KilledUnit(Unit* who)
            {

            }

            void JustSummoned(Creature* summon)
            {
                Summons.Summon(summon);
            }

            void EnterEvadeMode()
            {
                me->GetMotionMaster()->MoveTargetedHome();
                me->RemoveAllAuras();
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
                        case EVENT_VISCOUS_POISON:	
							if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                               DoCast(target, SPELL_VISCOUS_POISON);
                                    //target, SPELL_SHOCKWAVE, true);
                            }
                            events.ScheduleEvent(EVENT_VISCOUS_POISON, 100000);
                            break;

                        case EVENT_DUST_FLAIL:	
							if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
								DoCast(me, EVENT_DUST_FLAIL, true);
                            }
                            events.ScheduleEvent(EVENT_DUST_FLAIL, 15000);
                            break;

                        case EVENT_VENOMOUS_RAGE:	
							if (me->HealthBelowPct(30) && !me->HasAura(81706))
                            {
								me->AddAura(81706,me);
                                events.ScheduleEvent(EVENT_VENOMOUS_RAGE, 200000);
                            }
                            events.ScheduleEvent(EVENT_VENOMOUS_RAGE, 200);
                            break;

                        case EVENT_SCENT_OF_BLOOD:	
							if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
								DoCast(target, SPELL_SCENT_OF_BLOOD, true);
                            }
                            events.ScheduleEvent(EVENT_SCENT_OF_BLOOD, 200000);
                            break;

                        case EVENT_FRENZIED_CROCOLISK_SUMM:	
                            for(uint8 i = 0; i < 4; i++)
                            {
                                uint8 u = urand(1,4);
                                if (Creature * Guardian = me->SummonCreature(FRENZIED_CROCOLISK, SpawnPointGuardian[u], TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    DoZoneInCombat(Guardian);
                                }
                            }

                            events.ScheduleEvent(EVENT_FRENZIED_CROCOLISK_SUMM, 25000);
                            break;

                        case EVENT_SPAWN_AUGH:
                            if (Creature * Augh = me->SummonCreature(AUGH, -11021.297852f, -1654.381958f, 1.101078f, 2.695103f , TEMPSUMMON_MANUAL_DESPAWN))
                            {
                                DoZoneInCombat(Augh);
                            }
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_lockmawAI(creature);
        }
};

void AddSC_boss_lockmaw()
{
    new boss_lockmaw();
    new frenzied_crocolisk();
    new augh();
}