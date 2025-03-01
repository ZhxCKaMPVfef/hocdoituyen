CREATE TABLE khach_hang 
(
	Ma_KH CHAR(6),
	hovaten VARCHAR (25),
	diachi VARCHAR(25),
	PRIMARY KEY  (ma_kh)
);
CREATE TABLE loai_sd 
(
	ma_loai CHAR(2),
	tenloai VARCHAR (25),
	donggia INT,
	PRIMARY KEY  (ma_loai)
);
CREATE TABLE chitiet_sd 
(
	Ma_CTSD INT ,
	Ma_Kh CHAR(6),
	Ma_Loai CHAR(2),
	Thang INT, 
	SOKW INT,
	PRIMARY KEY  (Ma_CTSD)
);

INSERT INTO khach_hang Values
('KH0001', 'Lê Thanh', 'Sa Đéc'),
('KH002', 'Trần Tâm' , 'Lai Vung'),
('KH003', 'Nguyễn Sang' , 'Sa Đéc')
INSERT INTO loai_sd VALUES 
('KD',' Kinh Doanh', 1800),
('DD', 'Dân dụng', 1500)


INSERT INTO chitiet_sd VALUES
(1, 'KH0001', 'DD', 1 , 300),
(2, 'KH0002', 'KD', 1 , 500),
(3, 'KH0003', 'DD', 2 , 120),
(4, 'KH0004', 'KD', 2 , 350),
(5, 'KH0005', 'DD', 1 , 300)

SELECT *  FROM  khach_hang
Where diachi = 'Sa Đéc'
SELECT khach_hang.Ma_KH, khach_hang.hovaten,chitiet_sd.Ma_Loai, chitiet_sd.Thang,chitiet_sd.SOKW,
loai_sd.donggia*chitiet_sd.sokw AS thanhtien,
IF(chitiet_sd.SOKW>300, (loai_sd.donggia*chitiet_sd.sokw)*10/100 , 0) AS thue,

FROM khach_hang INNER JOIN chitiet_sd
ON khach_hang.Ma_KH = chitiet_sd.Ma_Kh
INNER JOIN loai_sd
ON chitiet_sd.Ma_Loai = loai_sd.ma_loai;
----------------------------------------
SELECT thang,AVG(SOKW), khach_hang.Ma_KH, khach_hang.hovaten, chitiet_sd.Ma_Kh AS totalkw
-- FROM chitiet_sd 
FROM khach_hang INNER JOIN chitiet_sd
on khach_hang.Ma_KH = chitiet_sd.Ma_KH
GROUP BY thang
