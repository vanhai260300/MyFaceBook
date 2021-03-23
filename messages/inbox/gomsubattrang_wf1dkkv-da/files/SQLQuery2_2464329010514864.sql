ALTER TABLE SinhVien
	add constraint cmnd_ck check ( CMND like'[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
		constraint cmnd_unique unique(CMND),
		constraint dob_ck check (DateDiff(year,DoB,getDate())>=18),
		constraint diachi_df default N'Đà Nẵng' for DiaChi with values
ALTER TABLE LopHP
	add constraint ssmax_df default 60 for SSMax with values,
		constraint ssmax_ck check(SSMax>0),
		constraint ssdangky_ck check (SSDangKy <= SSMax)

