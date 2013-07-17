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



class boss_high_prophet_barim : public CreatureScript
{
    public:
        boss_high_prophet_barim() : CreatureScript("high_prophet_barim") { }

        struct boss_high_prophet_barimAI : public BossAI
        {
            boss_high_prophet_barimAI(Creature* creature) : BossAI(creature, DATA_HIGH_PROPETH_BARIM)
            {

            }

            void Reset()
            {
                _Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(YELL_AGGRO);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(YELL_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
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

                DoMeleeAttackIfReady();
            }
        };
        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_high_prophet_barimAI(creature);
        }
};

void AddSC_boss_high_prophet_barim()
{
    new boss_high_prophet_barim();
}