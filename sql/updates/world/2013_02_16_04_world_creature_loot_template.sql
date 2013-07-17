-- Remove Zulian Mudskunk from Zulian Crocolisk's loot template
DELETE FROM `creature_loot_template` WHERE `entry`=15043 and `item`=19975;
-- Add Vicious Oil (Item) into loot template of Vicious Oil (NPC)
DELETE FROM `creature_loot_template` WHERE `entry`=30325 and `item`=42640;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) values
(30325,42640,-100,1,0,1,1);

INSERT IGNORE INTO creature_loot_template (entry, item, ChanceOrQuestChance, lootmode, groupid, mincountOrRef, maxcount)
        							VALUES(37105, 2787, 1.5                , 1       , 0      , 1            , 1       ),
                                          (37105, 49747,0.01               , 1       , 0      , 1            , 1       ),
                                          (37105, 3297, 0.01               , 1       , 0      , 1            , 1       ),
                                          (37105, 159 , 1.4                , 1       , 0      , 1            , 1       ),
                                          (37105, 4496, 0.17               , 1       , 0      , 1            , 1       ),
		          						  (37105, 805, 0.17	   			   , 1		 , 0	  , 1			 , 1	   ),
                                          (37105, 2589, 0.02               , 1       , 0      , 1            , 2       ),
                                          (37105, 62328, 0.01              , 1       , 0      , 1            , 1       );
