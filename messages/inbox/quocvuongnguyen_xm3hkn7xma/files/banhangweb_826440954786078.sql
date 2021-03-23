-- phpMyAdmin SQL Dump
-- version 5.0.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 12, 2020 at 02:11 AM
-- Server version: 10.4.14-MariaDB
-- PHP Version: 7.2.34

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `banhangweb`
--

-- --------------------------------------------------------

--
-- Table structure for table `nhomsanpham`
--

CREATE TABLE `nhomsanpham` (
  `Id` varchar(10) COLLATE utf8mb4_vietnamese_ci NOT NULL,
  `TenNhom` text COLLATE utf8mb4_vietnamese_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_vietnamese_ci;

--
-- Dumping data for table `nhomsanpham`
--

INSERT INTO `nhomsanpham` (`Id`, `TenNhom`) VALUES
('1', 'Acer'),
('2', 'Asus'),
('3', 'Dell'),
('4', 'Apple');

-- --------------------------------------------------------

--
-- Table structure for table `sanpham`
--

CREATE TABLE `sanpham` (
  `Id` varchar(10) COLLATE utf8mb4_vietnamese_ci NOT NULL,
  `IdNhomSP` varchar(10) COLLATE utf8mb4_vietnamese_ci NOT NULL,
  `TenSP` text COLLATE utf8mb4_vietnamese_ci DEFAULT NULL,
  `GiaSP` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_vietnamese_ci;

--
-- Dumping data for table `sanpham`
--

INSERT INTO `sanpham` (`Id`, `IdNhomSP`, `TenSP`, `GiaSP`) VALUES
('1', '1', 'Acer Aspire A515', 22500000),
('3', '3', 'Dell V3590', 20000000),
('4', '4', 'MacBook Air', 25000000);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `nhomsanpham`
--
ALTER TABLE `nhomsanpham`
  ADD PRIMARY KEY (`Id`);

--
-- Indexes for table `sanpham`
--
ALTER TABLE `sanpham`
  ADD PRIMARY KEY (`Id`),
  ADD KEY `IdNhomSP` (`IdNhomSP`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `sanpham`
--
ALTER TABLE `sanpham`
  ADD CONSTRAINT `sanpham_ibfk_1` FOREIGN KEY (`IdNhomSP`) REFERENCES `nhomsanpham` (`Id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
