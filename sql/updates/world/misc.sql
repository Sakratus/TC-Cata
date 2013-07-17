-- Wanted: Thaelis the Hungerer
UPDATE `gameobject_template` SET `flags` = flags &~ 4 WHERE `entry` = 180918;

-- Quest [Beating them Back!]
 
UPDATE `quest_template` SET `RequiredClasses`=1 WHERE `Id`=28766;
UPDATE `quest_template` SET `RequiredClasses`=2 WHERE `Id`=28762;
UPDATE `quest_template` SET `RequiredClasses`=4 WHERE `Id`=28767;
UPDATE `quest_template` SET `RequiredClasses`=8 WHERE `Id`=28764;
UPDATE `quest_template` SET `RequiredClasses`=16 WHERE `Id`=28763;
UPDATE `quest_template` SET `RequiredClasses`=128 WHERE `Id`=28757;
UPDATE `quest_template` SET `RequiredClasses`=256 WHERE `Id`=28765;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28766;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28762;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28767;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28764;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28763;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28757;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28765;
 
-- Quest [Lions for Lambs]
 
UPDATE `quest_template` SET `RequiredClasses`=1 WHERE `Id`=28774;
UPDATE `quest_template` SET `RequiredClasses`=2 WHERE `Id`=28770;
UPDATE `quest_template` SET `RequiredClasses`=4 WHERE `Id`=28759;
UPDATE `quest_template` SET `RequiredClasses`=8 WHERE `Id`=28772;
UPDATE `quest_template` SET `RequiredClasses`=16 WHERE `Id`=28771;
UPDATE `quest_template` SET `RequiredClasses`=128 WHERE `Id`=28769;
UPDATE `quest_template` SET `RequiredClasses`=256 WHERE `Id`=28773;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28774;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28770;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28759;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28772;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28771;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28769;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28773;
 
-- Quest [Join the Battle!]
 
UPDATE `quest_template` SET `RequiredClasses`=1 WHERE `Id`=28789;
UPDATE `quest_template` SET `RequiredClasses`=2 WHERE `Id`=28785;
UPDATE `quest_template` SET `RequiredClasses`=4 WHERE `Id`=28780;
UPDATE `quest_template` SET `RequiredClasses`=8 WHERE `Id`=28787;
UPDATE `quest_template` SET `RequiredClasses`=16 WHERE `Id`=28786;
UPDATE `quest_template` SET `RequiredClasses`=128 WHERE `Id`=28784;
UPDATE `quest_template` SET `RequiredClasses`=256 WHERE `Id`=28788;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28789;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28785;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28780;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28787;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28786;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28784;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28788;
 
-- Quest [They Sent Assassins]
 
UPDATE `quest_template` SET `RequiredClasses`=1 WHERE `Id`=28797;
UPDATE `quest_template` SET `RequiredClasses`=2 WHERE `Id`=28793;
UPDATE `quest_template` SET `RequiredClasses`=4 WHERE `Id`=28791;
UPDATE `quest_template` SET `RequiredClasses`=8 WHERE `Id`=28795;
UPDATE `quest_template` SET `RequiredClasses`=16 WHERE `Id`=28794;
UPDATE `quest_template` SET `RequiredClasses`=128 WHERE `Id`=28792;
UPDATE `quest_template` SET `RequiredClasses`=256 WHERE `Id`=28796;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28797;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28793;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28791;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28795;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28794;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28792;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28796;
 
-- Quest [The Rear is Clear]
 
UPDATE `quest_template` SET `RequiredClasses`=1 WHERE `Id`=28823;
UPDATE `quest_template` SET `RequiredClasses`=2 WHERE `Id`=28819;
UPDATE `quest_template` SET `RequiredClasses`=4 WHERE `Id`=28817;
UPDATE `quest_template` SET `RequiredClasses`=8 WHERE `Id`=28821;
UPDATE `quest_template` SET `RequiredClasses`=16 WHERE `Id`=28820;
UPDATE `quest_template` SET `RequiredClasses`=128 WHERE `Id`=28818;
UPDATE `quest_template` SET `RequiredClasses`=256 WHERE `Id`=28822;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28823;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28819;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28817;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28821;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28820;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28818;
UPDATE `quest_template` SET `RequiredRaces`=1 WHERE `Id`=28822;
 
-- Quest [Blackrock Invasion]
 
UPDATE `quest_template` SET `RequiredClasses`=0 WHERE `Id`=26389;
 
-- Quest [Ending the Invasion!]
 
UPDATE `quest_template` SET `RequiredClasses`=0 WHERE `Id`=26390;
 
-- Quest [Report to Goldshire]
 
UPDATE `quest_template` SET `RequiredClasses`=0 WHERE `Id`=54;

-- MAGE
-- Beating them back
UPDATE quest_template SET PrevQuestId = 0, NextQuestId = 28769 WHERE id = 28757;
-- Lions for lambs
UPDATE quest_template SET PrevQuestId = 28757, NextQuestId = 3104 WHERE id = 28769;
-- Glyphic letter
UPDATE quest_template SET PrevQuestId = 28769, NextQuestId = 26916 WHERE id = 3104;
-- Mastering the arcane
UPDATE quest_template SET PrevQuestId = 3104, NextQuestId = 28784 WHERE id = 26916;
-- Join the battle!
UPDATE quest_template SET PrevQuestId = 26916, NextQuestId = 28792 WHERE id = 28784;
-- They sent assassins
UPDATE quest_template SET PrevQuestId = 28784, NextQuestId = 28818 WHERE id = 28792;
-- The rear is clear
UPDATE quest_template SET PrevQuestId = 28792, NextQuestId = 26389 WHERE id = 28818;


-- PALADIN
UPDATE `quest_template` SET `RequiredRaces`= 0 WHERE `Id`=3101;
UPDATE `quest_template` SET `RequiredRaces`= 0 WHERE `Id`=26918;
-- Beating them back
UPDATE quest_template SET PrevQuestId = 0, NextQuestId = 28770 WHERE id = 28762;
-- Lions for lambs
UPDATE quest_template SET PrevQuestId = 28762, NextQuestId = 3101 WHERE id = 28770;
-- Consecrated letter
UPDATE quest_template SET PrevQuestId = 28770, NextQuestId = 26918 WHERE id = 3101;
-- The power of the light
UPDATE quest_template SET PrevQuestId = 3101, NextQuestId = 28785 WHERE id = 26918;
-- Join the battle
UPDATE quest_template SET PrevQuestId = 26918, NextQuestId = 28793 WHERE id = 28785;
-- They sent assassins
UPDATE quest_template SET PrevQuestId = 28785, NextQuestId = 28819 WHERE id = 28793;
-- The rear is clear
UPDATE quest_template SET PrevQuestId = 28793, NextQuestId = 26389 WHERE id = 28819;

-- Warrior
-- Beating them back
UPDATE quest_template SET PrevQuestId = 0, NextQuestId = 28774 WHERE id = 28766;
-- Lions for lambs
UPDATE quest_template SET PrevQuestId = 28766, NextQuestId = 3100 WHERE id = 28774;
-- Simple letter
UPDATE quest_template SET PrevQuestId = 28774, NextQuestId = 26913 WHERE id = 3100;
-- The Charging into battle
UPDATE quest_template SET PrevQuestId = 3100, NextQuestId = 28789 WHERE id = 26913;
-- Join the battle
UPDATE quest_template SET PrevQuestId = 26913, NextQuestId = 28797 WHERE id = 28789;
-- They sent assassins
UPDATE quest_template SET PrevQuestId = 28789, NextQuestId = 28823 WHERE id = 28797;
-- The rear is clear
UPDATE quest_template SET PrevQuestId = 28797, NextQuestId = 26389 WHERE id = 28823;

-- Hunter
-- Beating them back
UPDATE quest_template SET PrevQuestId = 0, NextQuestId = 28759 WHERE id = 28767;
-- Lions for lambs
UPDATE quest_template SET PrevQuestId = 28767, NextQuestId = 26910 WHERE id = 28759;
-- Etched letter
UPDATE quest_template SET PrevQuestId = 28759, NextQuestId = 26917 WHERE id = 26910;
-- The hunters path
UPDATE quest_template SET PrevQuestId = 26910, NextQuestId = 28780 WHERE id = 26917;
-- Join the battle
UPDATE quest_template SET PrevQuestId = 26917, NextQuestId = 28791 WHERE id = 28780;
-- They sent assassins
UPDATE quest_template SET PrevQuestId = 28780, NextQuestId = 28817 WHERE id = 28791;
-- The rear is clear
UPDATE quest_template SET PrevQuestId = 28791, NextQuestId = 26389 WHERE id = 28817;

-- Warlock
UPDATE `quest_template` SET `RequiredRaces`= 0 WHERE `Id`=3105;
UPDATE `quest_template` SET `RequiredRaces`= 0 WHERE `Id`=26914;
-- Beating them back
UPDATE quest_template SET PrevQuestId = 0, NextQuestId = 28773 WHERE id = 28765;
-- Lions for lambs
UPDATE quest_template SET PrevQuestId = 28765, NextQuestId = 3105 WHERE id = 28773;
-- Tainted letter
UPDATE quest_template SET PrevQuestId = 28773, NextQuestId = 26914 WHERE id = 3105;
-- Immolation
UPDATE quest_template SET PrevQuestId = 3105, NextQuestId = 28788 WHERE id = 26914;
-- Join the battle
UPDATE quest_template SET PrevQuestId = 26914, NextQuestId = 28796 WHERE id = 28788;
-- They sent assassins
UPDATE quest_template SET PrevQuestId = 28788, NextQuestId = 28822 WHERE id = 28796;
-- The rear is clear
UPDATE quest_template SET PrevQuestId = 28796, NextQuestId = 26389 WHERE id = 28822;

-- Priest
-- Beating them back
UPDATE quest_template SET PrevQuestId = 0, NextQuestId = 28771 WHERE id = 28763;
-- Lions for lambs
UPDATE quest_template SET PrevQuestId = 28763, NextQuestId = 3103 WHERE id = 28771;
-- Hallowed letter
UPDATE quest_template SET PrevQuestId = 28771, NextQuestId = 26919 WHERE id = 3103;
-- Healing the wounded
UPDATE quest_template SET PrevQuestId = 3103, NextQuestId = 28786 WHERE id = 26919;
-- Join the battle
UPDATE quest_template SET PrevQuestId = 26919, NextQuestId = 28794 WHERE id = 28786;
-- They sent assassins
UPDATE quest_template SET PrevQuestId = 28786, NextQuestId = 28820 WHERE id = 28794;
-- The rear is clear
UPDATE quest_template SET PrevQuestId = 28794, NextQuestId = 26389 WHERE id = 28820;

-- Rogue
UPDATE `quest_template` SET `RequiredRaces`= 0 WHERE `Id`=3102;
UPDATE `quest_template` SET `RequiredRaces`= 0 WHERE `Id`=26915;
-- Beating them back
UPDATE quest_template SET PrevQuestId = 0, NextQuestId = 28772 WHERE id = 28764;
-- Lions for lambs
UPDATE quest_template SET PrevQuestId = 28764, NextQuestId = 3102 WHERE id = 28772;
-- Encrypted letter
UPDATE quest_template SET PrevQuestId = 28772, NextQuestId = 26915 WHERE id = 3102;
-- The deepest cut
UPDATE quest_template SET PrevQuestId = 3102, NextQuestId = 28787 WHERE id = 26915;
-- Join the battle
UPDATE quest_template SET PrevQuestId = 26915, NextQuestId = 28795 WHERE id = 28787;
-- They sent assassins
UPDATE quest_template SET PrevQuestId = 28787, NextQuestId = 28821 WHERE id = 28795;
-- The rear is clear
UPDATE quest_template SET PrevQuestId = 28795, NextQuestId = 26389 WHERE id = 28821;

-- Blackrock invasion
UPDATE quest_template SET PrevQuestId = 0, NextQuestId = 26390 WHERE id = 26389;
-- Ending the invasion
UPDATE quest_template SET PrevQuestId = 26389, NextQuestId = 54 WHERE id = 26390;
-- Report to goldshire
UPDATE quest_template SET PrevQuestId = 26390, NextQuestId = 0 WHERE id = 54;

-- Ostatni rasy
-- Beating them back
UPDATE quest_template SET PrevQuestId = 0, NextQuestId = 29079 WHERE id = 29078;
-- Lions for lambs
UPDATE quest_template SET PrevQuestId = 29078, NextQuestId = 29080 WHERE id = 29079;
-- Join the battle
UPDATE quest_template SET PrevQuestId = 29079, NextQuestId = 29081 WHERE id = 29080;
-- They sent assassins
UPDATE quest_template SET PrevQuestId = 29080, NextQuestId = 29083 WHERE id = 29081;
-- The rear is clear
UPDATE quest_template SET PrevQuestId = 29081, NextQuestId = 26389 WHERE id = 29083;

UPDATE `quest_template` SET `RequiredRaces`= 2098252 WHERE `Id`=29078;
UPDATE `quest_template` SET `RequiredRaces`= 2098252 WHERE `Id`=29079;
UPDATE `quest_template` SET `RequiredRaces`= 2098252 WHERE `Id`=29080;
UPDATE `quest_template` SET `RequiredRaces`= 2098252 WHERE `Id`=29081;
UPDATE `quest_template` SET `RequiredRaces`= 2098252 WHERE `Id`=29083;

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 19 AND SourceEntry IN 27761,27777,27778,27779;
DELETE FROM conditions WHERE SourceTypeOrReferenceId = 20 AND SourceEntry IN 27761,27777,27778,27779;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 27761, 0, 0, 8, 0, 27760, 0, 0, 0, 0, 0, '', 'Quest Accept 27761 If Quest Rewarded 27760'),
(20, 0, 27761, 0, 0, 8, 0, 27760, 0, 0, 0, 0, 0, '', 'Show Quest Mark 27761 If Quest Rewarded 27760'),
(19, 0, 27777, 0, 0, 8, 0, 27760, 0, 0, 0, 0, 0, '', 'Quest Accept 27777 If Quest Rewarded 27760'),
(20, 0, 27777, 0, 0, 8, 0, 27760, 0, 0, 0, 0, 0, '', 'Show Quest Mark 27777 If Quest Rewarded 27760'),
(19, 0, 27778, 0, 0, 8, 0, 27761, 0, 0, 0, 0, 0, '', 'Quest Accept 27778 If Quest Rewarded 27761'),
(20, 0, 27778, 0, 0, 8, 0, 27761, 0, 0, 0, 0, 0, '', 'Show Quest Mark 27778 If Quest Rewarded 27761'),
(19, 0, 27778, 0, 0, 8, 0, 27777, 0, 0, 0, 0, 0, '', 'Quest Accept 27778 If Quest Rewarded 27777'),
(20, 0, 27778, 0, 0, 8, 0, 27777, 0, 0, 0, 0, 0, '', 'Show Quest Mark 27778 If Quest Rewarded 27777'),
(19, 0, 27779, 0, 0, 8, 0, 27778, 0, 0, 0, 0, 0, '', 'Quest Accept 27779 If Quest Rewarded 27778'),
(20, 0, 27779, 0, 0, 8, 0, 27778, 0, 0, 0, 0, 0, '', 'Show Quest Mark 27779 If Quest Rewarded 27778');

-- Servants of cho'gall chain
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 27078, 0, 0, 8, 0, 27075, 0, 0, 0, 0, 0, '', 'Quest Accept 27078 If Quest Rewarded 27075'),
(20, 0, 27078, 0, 0, 8, 0, 27075, 0, 0, 0, 0, 0, '', 'Show Quest Mark 27078 If Quest Rewarded 27075'),
(19, 0, 27078, 0, 0, 8, 0, 27077, 0, 0, 0, 0, 0, '', 'Quest Accept 27078 If Quest Rewarded 27077'),
(20, 0, 27078, 0, 0, 8, 0, 27077, 0, 0, 0, 0, 0, '', 'Show Quest Mark 27078 If Quest Rewarded 27077'),
(19, 0, 27115, 0, 0, 8, 0, 27078, 0, 0, 0, 0, 0, '', 'Quest Accept 27115 If Quest Rewarded 27078'),
(20, 0, 27115, 0, 0, 8, 0, 27078, 0, 0, 0, 0, 0, '', 'Show Quest Mark 27115 If Quest Rewarded 27078'),
(19, 0, 27116, 0, 0, 8, 0, 27115, 0, 0, 0, 0, 0, '', 'Quest Accept 27116 If Quest Rewarded 27115'),
(20, 0, 27116, 0, 0, 8, 0, 27115, 0, 0, 0, 0, 0, '', 'Show Quest Mark 27116 If Quest Rewarded 27115')

-- Extinguishing the hope
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 42940;
DELETE FROM `smart_scripts` WHERE entryorguid = 42940;
INSERT INTO `smart_scripts` VALUES
(42940, 0, 0, 1, 8, 0, 100, 0, 80208, 0, 0, 0, 33, 42940, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Creature/Gameobject Spell Hit - Call KilledMonster'),
(42940, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On EventLink - Force Despawn'),
(42940, 0, 2, 0, 11, 0, 100, 0, 0, 0, 0, 0, 75, 80175, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Creature/Gameobject Respawn. - Add Aura');

DELETE FROM `disables` WHERE sourceType = 0 AND entry = 80199;
INSERT INTO `disables` VALUES (0, 80199, 64, 0, 0, 'LOS');

UPDATE `creature_template` SET `flags_extra` = '128 ' WHERE `entry` = 42940;
UPDATE quest_template SET PrevQuestId = 26389, NextQuestId = 0 WHERE id = 26391;

-- Bounty on murlocs
UPDATE quest_template SET PrevQuestId = 0, NextQuestId = 0 WHERE id = 46;

-- The escape
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 251;
DELETE FROM `smart_scripts` WHERE entryorguid = 251;
INSERT INTO `smart_scripts` VALUES
(251, 0, 0, 1, 20, 0, 100, 0, 114, 0, 0, 0, 1, 0, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Target Rewarded Quest - Say text.'),
(251, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On EventLink - Force Despawn');

-- Duskwoood start chain
-- Look to the stars
UPDATE quest_template SET PrevQuestId = 26618, NextQuestId = 26684 WHERE id = 26683;
-- The hermit
UPDATE quest_template SET PrevQuestId = 26618, NextQuestId = 26653 WHERE id = 26627;
-- The night watch
UPDATE quest_template SET PrevQuestId = 26618, NextQuestId = 26686 WHERE id = 26645;

-- Made by [Ex]Gigant