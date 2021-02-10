-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Czas generowania: 29 Cze 2020, 03:24
-- Wersja serwera: 10.4.11-MariaDB
-- Wersja PHP: 7.4.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `gamerpg`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `heroe`
--

CREATE TABLE `heroe` (
  `idHeroe` int(10) UNSIGNED NOT NULL,
  `class_heroe` int(10) UNSIGNED NOT NULL,
  `name` varchar(20) NOT NULL,
  `level` int(10) UNSIGNED NOT NULL,
  `exp` int(10) UNSIGNED NOT NULL,
  `money` int(10) UNSIGNED NOT NULL,
  `health` int(10) UNSIGNED NOT NULL,
  `strength` int(10) UNSIGNED NOT NULL,
  `dexterity` int(10) UNSIGNED NOT NULL,
  `magic` int(10) UNSIGNED NOT NULL,
  `defence` int(10) UNSIGNED NOT NULL,
  `luck` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `heroe`
--

INSERT INTO `heroe` (`idHeroe`, `class_heroe`, `name`, `level`, `exp`, `money`, `health`, `strength`, `dexterity`, `magic`, `defence`, `luck`) VALUES
(1, 1, 'PostacAdmina', 5, 3210, 88, 800, 20, 10, 0, 15, 10),
(2, 2, 'Ala', 5, 250, 5, 400, 5, 20, 5, 10, 10),
(7, 3, 'maciej', 1, 371, 62, 100, 1, 1, 10, 10, 1),
(8, 2, 'pro', 1, 1, 0, 100, 10, 1, 1, 10, 1),
(13, 1, 'qqq', 1, 11, 15, 100, 1, 10, 1, 10, 1),
(18, 2, 'ala ma psa', 1, 1, 10, 100, 10, 1, 1, 10, 1);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `heroes`
--

CREATE TABLE `heroes` (
  `Users_idUsers` int(10) UNSIGNED NOT NULL,
  `idHeroes` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `heroes`
--

INSERT INTO `heroes` (`Users_idUsers`, `idHeroes`) VALUES
(1, 1),
(1, 2),
(7, 7),
(6, 8),
(6, 13),
(1, 18);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `users`
--

CREATE TABLE `users` (
  `idUsers` int(10) UNSIGNED NOT NULL,
  `login` varchar(45) NOT NULL,
  `passwd` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `users`
--

INSERT INTO `users` (`idUsers`, `login`, `passwd`) VALUES
(1, 'admin', '21232f297a57a5a743894a0e4a801fc3'),
(5, '123	', '202cb962ac59075b964b07152d234b70'),
(6, 'aa', '3691308f2a4c2f6983f2880d32e29c84'),
(7, 'maciek', 'e10adc3949ba59abbe56e057f20f883e');

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `heroe`
--
ALTER TABLE `heroe`
  ADD PRIMARY KEY (`idHeroe`);

--
-- Indeksy dla tabeli `heroes`
--
ALTER TABLE `heroes`
  ADD KEY `Heroes_FKIndex1` (`Users_idUsers`);

--
-- Indeksy dla tabeli `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`idUsers`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT dla tabeli `heroe`
--
ALTER TABLE `heroe`
  MODIFY `idHeroe` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT dla tabeli `users`
--
ALTER TABLE `users`
  MODIFY `idUsers` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
