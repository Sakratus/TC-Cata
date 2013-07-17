DROP TABLE IF EXISTS gossip_menu_option;
CREATE TABLE gossip_menu_option (
  menu_id smallint(6) unsigned NOT NULL default '0',
  id smallint(6) unsigned NOT NULL default '0',
  option_icon mediumint(8) unsigned NOT NULL default '0',
  option_text text,
  option_id tinyint(3) unsigned NOT NULL default '0',
  npc_option_npcflag int(10) unsigned NOT NULL default '0',
  action_menu_id mediumint(8) unsigned NOT NULL default '0',
  action_poi_id mediumint(8) unsigned NOT NULL default '0',
  action_script_id mediumint(8) unsigned NOT NULL default '0',
  box_coded tinyint(3) unsigned NOT NULL default '0',
  box_money int(11) unsigned NOT NULL default '0',
  box_text text,
  cond_1 tinyint(3) unsigned NOT NULL default '0',
  cond_1_val_1 mediumint(8) unsigned NOT NULL default '0',
  cond_1_val_2 mediumint(8) unsigned NOT NULL default '0',
  cond_2 tinyint(3) unsigned NOT NULL default '0',
  cond_2_val_1 mediumint(8) unsigned NOT NULL default '0',
  cond_2_val_2 mediumint(8) unsigned NOT NULL default '0',
  cond_3 tinyint(3) unsigned NOT NULL default '0',
  cond_3_val_1 mediumint(8) unsigned NOT NULL default '0',
  cond_3_val_2 mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY (menu_id, id)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DELETE FROM gossip_menu_option WHERE menu_id=0;
INSERT INTO gossip_menu_option VALUES
(0,0,0,'GOSSIP_OPTION_QUESTGIVER',2,2,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,1,1,'GOSSIP_OPTION_VENDOR',3,128,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,2,2,'GOSSIP_OPTION_TAXIVENDOR',4,8192,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,3,3,'GOSSIP_OPTION_TRAINER',5,16,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,4,4,'GOSSIP_OPTION_SPIRITHEALER',6,16384,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,5,4,'GOSSIP_OPTION_SPIRITGUIDE',7,32768,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,6,5,'GOSSIP_OPTION_INNKEEPER',8,65536,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,7,6,'GOSSIP_OPTION_BANKER',9,131072,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,8,7,'GOSSIP_OPTION_PETITIONER',10,262144,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,9,8,'GOSSIP_OPTION_TABARDDESIGNER',11,524288,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,10,9,'GOSSIP_OPTION_BATTLEFIELD',12,1048576,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,11,6,'GOSSIP_OPTION_AUCTIONEER',13,2097152,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,12,0,'GOSSIP_OPTION_STABLEPET',14,4194304,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,13,1,'GOSSIP_OPTION_ARMORER',15,4096,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,14,2,'GOSSIP_OPTION_UNLEARNTALENTS',16,16,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,15,2,'GOSSIP_OPTION_UNLEARNPETSKILLS',17,16,0,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0),
(0,16,2,'GOSSIP_OPTION_LEARNDUALSPEC',18,16,0,0,0,0,10000000,NULL,0,0,0,0,0,0,0,0,0),
(0,17,0,'GOSSIP_OPTION_OUTDOORPVP',1,19,536870912,0,0,0,0,NULL,0,0,0,0,0,0,0,0,0);

UPDATE gossip_menu_option SET option_id = 3 WHERE menu_id = 10898;
UPDATE gossip_menu_option SET npc_option_npcflag = 131 WHERE menu_id = 10898;