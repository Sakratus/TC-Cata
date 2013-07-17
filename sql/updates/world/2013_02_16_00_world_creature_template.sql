UPDATE `creature_template` SET `Armor_mod`=0 WHERE `entry`=29747;
UPDATE creature_template SET npcflag = 131 WHERE entry = 8416;

UPDATE creature_template SET maxgold = 5, mingold = 1 WHERE entry = 37105;
UPDATE creature_template SET spell1 = 69897 WHERE entry = 37105;
UPDATE creature_template SET movementtype = 1 WHERE entry = 37105;
UPDATE creature_template SET scriptname = 'npc_rockjaw_scavenger' WHERE entry = 37105;