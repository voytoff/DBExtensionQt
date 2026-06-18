-- --------------------------------------------------------
-- Хост:                         127.0.0.1
-- Версия сервера:               12.3.2-MariaDB - MariaDB Server
-- Операционная система:         Win64
-- HeidiSQL Версия:              12.17.0.7270
-- --------------------------------------------------------

-- Дамп структуры базы данных 106org
DROP DATABASE IF EXISTS `106org`;
CREATE DATABASE IF NOT EXISTS `106org`;
USE `106org`;

-- Дамп структуры для таблица 106org.crate
DROP TABLE IF EXISTS `crate`;
CREATE TABLE IF NOT EXISTS `crate` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  `host` varchar(20) DEFAULT '127.0.0.1',
  `port` int(11) DEFAULT 11111,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT COMMENT='Таблица крейтов';

-- Экспортируемые данные не выделены.

-- Дамп структуры для таблица 106org.module
DROP TABLE IF EXISTS `module`;
CREATE TABLE IF NOT EXISTS `module` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `crate_id` int(11) DEFAULT NULL COMMENT 'Связующий столбец с таблицей crate',
  `name` varchar(50) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`),
  KEY `FK_crate_module` (`crate_id`),
  CONSTRAINT `FK_crate_module` FOREIGN KEY (`crate_id`) REFERENCES `crate` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT COMMENT='LTR-модуль крейта';
