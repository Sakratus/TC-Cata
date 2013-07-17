-- Prolific writer
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, ConditionTypeOrReference, ConditionValue1) VALUES (15, 12287, 0, 9, 28002);
UPDATE `creature_template` SET `gossip_menu_id` = '12287' WHERE `entry` = 47516;
DELETE FROM `gossip_menu` WHERE entry = 12287;
DELETE FROM `gossip_menu` WHERE entry = 12285;
DELETE FROM `gossip_menu` WHERE entry = 12286;
INSERT INTO `gossip_menu` (entry, text_id) VALUES (12287, 17252);
INSERT INTO `gossip_menu` (entry, text_id) VALUES (12285, 17253);
INSERT INTO `gossip_menu` (entry, text_id) VALUES (12286, 17254);

UPDATE `gossip_menu_option` SET npc_option_npcflag= 1 WHERE menu_id = 12287;
UPDATE `gossip_menu_option` SET option_id= 1 WHERE menu_id = 12287;
UPDATE `gossip_menu_option` SET npc_option_npcflag= 1 WHERE menu_id = 12286;
UPDATE `gossip_menu_option` SET option_id= 1 WHERE menu_id = 12286;
UPDATE `gossip_menu_option` SET npc_option_npcflag= 1 WHERE menu_id = 12285;
UPDATE `gossip_menu_option` SET option_id= 1 WHERE menu_id = 12285;

UPDATE `gossip_menu_option` SET action_menu_id= 12285 WHERE menu_id = 12287;
UPDATE `gossip_menu_option` SET action_menu_id= 12286 WHERE menu_id = 12285;
UPDATE `gossip_menu_option` SET action_menu_id= 0 WHERE menu_id = 12286;

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 47516;
DELETE FROM `smart_scripts` WHERE entryorguid = 47516;
INSERT INTO `smart_scripts` VALUES
(47516, 0, 0, 1, 62, 0, 100, 0, 12286, 0, 0, 0, 33, 47516, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On GossipSelect - Call KilledMonster'),
(47516, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 98, 0, 17255, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On EventLink - Send Gossip Menu');

-- Pretentios businessman
DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 28002;
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, ConditionTypeOrReference, ConditionValue1) VALUES (15, 12314, 0, 9, 28002);
UPDATE `creature_template` SET `gossip_menu_id` = '12314' WHERE `entry` = 47520;
DELETE FROM `gossip_menu` WHERE entry = 12314;
DELETE FROM `gossip_menu` WHERE entry = 12315;
INSERT INTO `gossip_menu` (entry, text_id) VALUES (12314, 17309);
INSERT INTO `gossip_menu` (entry, text_id) VALUES (12315, 17310);

UPDATE `gossip_menu_option` SET npc_option_npcflag= 1 WHERE menu_id = 12314;
UPDATE `gossip_menu_option` SET option_id= 1 WHERE menu_id = 12287;
UPDATE `gossip_menu_option` SET npc_option_npcflag= 1 WHERE menu_id = 12315;
UPDATE `gossip_menu_option` SET option_id= 1 WHERE menu_id = 12286;

UPDATE `gossip_menu_option` SET action_menu_id= 12315 WHERE menu_id = 12314;
UPDATE `gossip_menu_option` SET action_menu_id= 0 WHERE menu_id = 12315;

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 47520;
DELETE FROM `smart_scripts` WHERE entryorguid = 47520;
INSERT INTO `smart_scripts` VALUES
(47520, 0, 0, 1, 62, 0, 100, 0, 12315, 0, 0, 0, 33, 47520, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On GossipSelect - Call KilledMonster'),
(47520, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 98, 0, 17311, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On EventLink - Send Gossip Menu');


-- Privileged socialite
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, ConditionTypeOrReference, ConditionValue1) VALUES (15, 12288, 0, 9, 28002);
UPDATE `creature_template` SET `gossip_menu_id` = '12288' WHERE `entry` = 47519;
DELETE FROM `gossip_menu` WHERE entry = 12288;
DELETE FROM `gossip_menu` WHERE entry = 12289;
DELETE FROM `gossip_menu` WHERE entry = 12290;

INSERT INTO `gossip_menu` (entry, text_id) VALUES (12288, 17316);
INSERT INTO `gossip_menu` (entry, text_id) VALUES (12289, 17317);
INSERT INTO `gossip_menu` (entry, text_id) VALUES (12290, 17318);

UPDATE `gossip_menu_option` SET npc_option_npcflag= 1 WHERE menu_id = 12288;
UPDATE `gossip_menu_option` SET option_id= 1 WHERE menu_id = 12288;
UPDATE `gossip_menu_option` SET npc_option_npcflag= 1 WHERE menu_id = 12289;
UPDATE `gossip_menu_option` SET option_id= 1 WHERE menu_id = 12289;
UPDATE `gossip_menu_option` SET npc_option_npcflag= 1 WHERE menu_id = 12290;
UPDATE `gossip_menu_option` SET option_id= 1 WHERE menu_id = 12290;

UPDATE `gossip_menu_option` SET action_menu_id= 12289 WHERE menu_id = 12288;
UPDATE `gossip_menu_option` SET action_menu_id= 12290 WHERE menu_id = 12289;
UPDATE `gossip_menu_option` SET action_menu_id= 0 WHERE menu_id = 12290;

DELETE FROM `npc_text` WHERE id = 17316;
DELETE FROM `npc_text` WHERE id = 17317;
DELETE FROM `npc_text` WHERE id = 17318;
DELETE FROM `npc_text` WHERE id = 17320;

INSERT INTO `npc_text` (id, text0_0) VALUES (17316, 'Don\'t - don\'t touch me... What\'s happening?');
INSERT INTO `npc_text` (id, text0_0) VALUES (17317, 'No! Of course I\'m not alright! I-I\'ve never seen an actual corpse before...');
INSERT INTO `npc_text` (id, text0_0) VALUES (17318, 'He just came stumbling out of the bunker. I screamed for help, but the guards wouldn\'t even look at me!');
INSERT INTO `npc_text` (id, text0_0) VALUES (17320, 'Yes. That sounds like a good idea.');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 47519;
DELETE FROM `smart_scripts` WHERE entryorguid = 47519;
INSERT INTO `smart_scripts` VALUES
(47519, 0, 0, 1, 62, 0, 100, 0, 12290, 0, 0, 0, 33, 47519, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On GossipSelect - Call KilledMonster'),
(47519, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 98, 0, 17320, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On EventLink - Send Gossip Menu');


-- Budding artist
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, ConditionTypeOrReference, ConditionValue1) VALUES (15, 12319, 0, 9, 28002);
UPDATE `creature_template` SET `gossip_menu_id` = '12319' WHERE `entry` = 47707;

DELETE FROM `gossip_menu` WHERE entry = 12319;
DELETE FROM `gossip_menu` WHERE entry = 12318;

INSERT INTO `gossip_menu` (entry, text_id) VALUES (12319, 17312);
INSERT INTO `gossip_menu` (entry, text_id) VALUES (12318, 17313);

UPDATE `gossip_menu_option` SET npc_option_npcflag= 1 WHERE menu_id = 12318;
UPDATE `gossip_menu_option` SET option_id= 1 WHERE menu_id = 12318;
UPDATE `gossip_menu_option` SET npc_option_npcflag= 1 WHERE menu_id = 12319;
UPDATE `gossip_menu_option` SET option_id= 1 WHERE menu_id = 12319;

UPDATE `gossip_menu_option` SET action_menu_id= 12318 WHERE menu_id = 12319;
UPDATE `gossip_menu_option` SET action_menu_id= 0 WHERE menu_id = 12318;

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 47707;
DELETE FROM `smart_scripts` WHERE entryorguid = 47707;
INSERT INTO `smart_scripts` VALUES
(47707, 0, 0, 1, 62, 0, 100, 0, 12318, 0, 0, 0, 33, 47707, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On GossipSelect - Call KilledMonster'),
(47707, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 98, 0, 17314, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On EventLink - Send Gossip Menu');