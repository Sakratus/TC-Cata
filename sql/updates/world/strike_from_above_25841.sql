-- NPCs
UPDATE `creature_template` SET `ScriptName` = 'npc_covert_ops_machine' WHERE `entry` = 41382;

-- Spelly
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (77488, 'spell_strike_from_above_signal_flare');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (77477, 'spell_script_missile_barrage');

-- Objekty
DELETE FROM `gameobject` WHERE `id` = 182090 AND `map` = 0;
