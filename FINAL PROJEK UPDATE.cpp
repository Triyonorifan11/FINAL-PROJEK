#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
//Kelompok 8 Perograman Lanjut B081
//Nama Anggota:

//1. TRIYONO RIFAN 					(20081010003)
//2. SALMA FATHIYATUR RIZKY MUNIR 			(20081010025)
//3. AHMAD HILMAN DANI 					(20081010057)
//4. IBET MAULANA 					(20081010067)
//5. HAFID ALFA ANAMSYAH 				(20081010189)
//6. CHANDRA IKA NUGROHO 				(20081010212)

struct lokasi_kos{
	char provinsi[100];
	char Kabupaten[130];
	char jalan[150];
};


struct pemilik_kos{
	long long int harga;
	lokasi_kos lokasi;
	int fasilitas;
	int tipe;
	char NamaPemilikKos[200];
	float LebarKamar;
	float PanjangKamar;
	float LuasKamar;
	int IdKos;
}Kos, Cek, Update[300] ; 
struct pemilik_kos ArrayKos[300];


//inisialisasi
void Pemilik_Kos();
void Penyewa_Kos();
void input_kos();
void update_kos();
void lihat_kos();
void lihat_kos_UIpenyewa();
void exit();
void SewaCariKamar();
void SewaCariKamarTipe();
void SewaCariKamarProvinsi();
void SewaCariKamarKabupaten();
void SelectionSort_Asc();
void tukar();

int total_data = 0;


void exit(){
	system("Color 9f");
	system("cls");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================     Terima kasih telah menggunakan aplikasi Kos sederhana      ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");
	puts("\n\n\t\t\t\tDibuat oleh Kelompok 8 Final projek Pemrograman Lanjut B081");
	puts("\n\t\t\t\tFakultas Ilmu Komputer");
	puts("\n\t\t\t\tProgram Studi Informatika");
	puts("\n\t\t\t\tTerima kasih telah menggunakan Aplikasi ini\n\n\n");
}

void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
  //	return;
}

void mainMenu(){
	int pilih; //deklarasi variabel pilih
	system("Color 3f");
	system("cls");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================            Selamat datang di aplikasi Kos sederhana            ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");
	puts("\t\t\t =================================");
	puts("\t\t\t|| Siapa Anda? [Pemilik/Penyewa] ||");
	puts("\t\t\t =================================\n");
	puts("\t\t\t\t[1] Pemilik Kos\n");
	puts("\t\t\t\t[2] Penyewa Kos\n");
	puts("\t\t\t\t[3] Close Aplikasi\n");
	printf("\n\t\t\t\t\tMasukkan pilihan : "); scanf("%d", &pilih);
	switch(pilih){
		case 1:
			Pemilik_Kos();
			break;
		case 2:
			Penyewa_Kos();
			break;
		case 3:
			exit();
			break;
		default:
			puts("\n\n\t\t\t\t!!!! WARNING !!!!");
			printf("\n\t\t\t\tsilahkan masukkan pilihan dengan benar !!");
			system("Pause");
			mainMenu();
			break;
	}
}


void Pemilik_Kos(){
	system("cls");
	int pilih; //inisialisasi variabel pilih
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================             Laman ''Pemilik KOS'' di UMMIK KOS                 ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");
	puts("\t\t\t ===============================");
	puts("\t\t\t ||  Pilih Menu Pemilik Kos   ||");
	puts("\t\t\t ===============================\n");
	puts("\t\t\t\t[1] Input kamar\n");
	puts("\t\t\t\t[2] Update kamar\n");
	puts("\t\t\t\t[3] Lihat daftar kamar\n");
	puts("\t\t\t\t[4] Menu utama\n");
	puts("\t\t\t\t[5] Close\n\n");
	printf("\n\t\t\t\t\tMasukkan Pilihan : "); scanf("%d", &pilih);
	switch(pilih){
		case 1:
			input_kos();
			break;
		case 2:
			update_kos();
			break;
		case 3:
			lihat_kos();
			break;
		case 4:
			mainMenu();
			break;
		case 5:
			exit();
			break;
		default:
			puts("\t\t\t\t!!!! WARNING !!!!");
			printf("\n\t\t\t\tsilahkan masukkan pilihan dengan benar !!");
			system("Pause");
			Pemilik_Kos();
	}
}


void Penyewa_Kos(){
	system("cls");
	int pilih;
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================            Laman ''Penyewa'' KOS di UMMIK KOS                  ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");
	puts("\t\t\t ===============================");
	puts("\t\t\t ||  Pilih Menu Penyewa Kos   ||");
	puts("\t\t\t ===============================\n");
//	puts("\n\n\t\t\t Mohon maaf!! Menu dalam Pengembangan !!\n\n\n\n");
	printf("\t\t\t\t[1] Cari kamar tuk disewa\n");
	printf("\n\t\t\t\t[2] lihat daftar kamar\n");
	printf("\n\t\t\t\t[3] close\n");
	printf("\n\n\t\t\t\tMasukkan Pilihan : "); 
	scanf("%d", &pilih);
	switch(pilih){
		case 1:
			SewaCariKamar();
			break;
		case 2:
			lihat_kos_UIpenyewa();
			break;
		case 3:
			exit();
			break;
		default:
			puts("\n\n\t\t\t\t!!!! WARNING !!!!");
			printf("\n\t\t\t\tsilahkan masukkan pilihan dengan benar !!");
			system("Pause");
			Penyewa_Kos();
			break;
	}
	system("Pause");
	mainMenu();
}

//===================Fungsi Update Kos
void update_kos(){

	int i=0, j=0, index = 0;
	int cari_IdKos, pilih_update;
	
	FILE *view_FlagTotalData;
	view_FlagTotalData = fopen("Data Pemilik Kos/flag_data_pemilik_kos.txt","r");
	fscanf(view_FlagTotalData,"%d", &total_data);
	
	FILE *view_int;
	FILE *view_string_provinsi;
	FILE *view_string_kabupaten;
	FILE *view_string_jalan;
	FILE *view_NamaPemilikKos;
			
	view_int = fopen("Data Pemilik Kos/Ummik_Kos.txt","r");
	view_string_provinsi = fopen("Data Pemilik Kos/data_pemilik_kos_string_provinsi.txt","r");
	view_string_kabupaten = fopen("Data Pemilik Kos/data_pemilik_kos_string_kabupaten.txt","r");
	view_string_jalan = fopen("Data Pemilik Kos/data_pemilik_kos_string_jalan.txt","r");
	view_NamaPemilikKos = fopen("Data Pemilik Kos/NamaPemilik.txt","r");
	
	system("cls");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================             Laman ''Update'' KOS di UMMIK KOS                  ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");

			
	if(view_int==NULL)
	{
	
		printf("\n\n\n");
		puts("\t\t\t ===============================");
		puts("\t\t\t ||     Belum ada data KOS    ||");
		puts("\t\t\t ===============================\n");
	}
	
	else
	{
			
		while(!feof(view_int))
		{
			fflush(stdin);
						
			fscanf(view_int,"%d %lld %d %f %f %f %d", &ArrayKos[index].tipe, &ArrayKos[index].harga, &ArrayKos[index].fasilitas, &ArrayKos[index].PanjangKamar, &ArrayKos[index].LebarKamar, &ArrayKos[index].LuasKamar, &ArrayKos[index].IdKos);
			fflush(stdin);
							
			fscanf(view_string_provinsi," %[^\n]s", &ArrayKos[index].lokasi.provinsi);
		    fscanf(view_string_kabupaten," %[^\n]s", &ArrayKos[index].lokasi.Kabupaten);
		    fscanf(view_string_jalan," %[^\n]s", &ArrayKos[index].lokasi.jalan);
		    fscanf(view_NamaPemilikKos," %[^\n]s", &ArrayKos[index].NamaPemilikKos);
			index++;
		}
			
		fclose(view_FlagTotalData);
		fclose(view_string_provinsi);
		fclose(view_int);
		fclose(view_string_kabupaten);
		fclose(view_string_jalan);
		fclose(view_NamaPemilikKos);
		
		printf("\n\t\t\t\t\t=================== Menu Update Ummik Kos ==================\n\n");
		
		fflush(stdin);		
		printf("\n\t\t\t\tMasukkan ID kos yang akan di Update = ");
		scanf("%d", &cari_IdKos);
		
		FILE *Nama_baru;
		Nama_baru = fopen("Data Pemilik Kos/NamaPemilik_Update.txt","w");
		
		int flag = 0;
		for(i=0;i<index;i++)
		{
			if(cari_IdKos == ArrayKos[i].IdKos){
				flag = 1;
				ulangi_update:
				printf("========================================================================================================================================================================\n");
		        printf("|| \t\t\t\tID Kos\t: %d Akan di Update!\n", ArrayKos[i].IdKos);
		        printf("\n\n\t\t\t\t====Silahkan Pilih yang akan di Update====\n\n");
				printf("\n\t\t\t\t[1] Nama Pemilik Kos\n");
				printf("\n\t\t\t\t[2] Tipe Kos\n");
				printf("\n\t\t\t\t[3] Harga Kos\n");
				printf("\n\t\t\t\t[4] Fasilitas Kos\n");
				printf("\n\t\t\t\t[5] Kembali\n");
				printf("\n\t\t\t\tSilahkan Pilih dari menu diatas = ");
				scanf("%d", &pilih_update);
				
				if(pilih_update == 1){
					FILE *Nama_baru;
					Nama_baru = fopen("Data Pemilik Kos/NamaPemilik_Update.txt","w");
					printf("\n\t\t\t\tMasukkan Nama Pemilik Kos baru = ");
					scanf(" %[^\n]s", &Update[i].NamaPemilikKos);
					strcpy(ArrayKos[i].NamaPemilikKos, Update[i].NamaPemilikKos);
					
					FILE *fptr_flag_baru;
					fptr_flag_baru = fopen("Data Pemilik Kos/flag_data_pemilik_kos_update.txt","r");
					
					for(j = 0; j<index; j++){
						if(fptr_flag_baru == NULL){
							fprintf(Nama_baru, "%s", ArrayKos[j].NamaPemilikKos);	
						}
						else{
							fprintf(Nama_baru, "\n%s", ArrayKos[j].NamaPemilikKos);	
						}
					}
					fclose(fptr_flag_baru);
					printf("\n\t\t\t\t Data Telah Tersimpan\n\n");
					fclose(Nama_baru);
					remove("Data Pemilik Kos/NamaPemilik.txt");
					rename("Data Pemilik Kos/NamaPemilik_Update.txt", "Data Pemilik Kos/NamaPemilik.txt");
					
				}
				else if(pilih_update == 2){
					FILE *Tipe_baru;
					Tipe_baru = fopen("Data Pemilik Kos/Update_Ummik_Kos.txt","w");
					printf("\n\t\t\t\tMasukkan Tipe Kos baru = ");
					scanf("%d", &Update[i].tipe);
					ArrayKos[i].tipe = Update[i].tipe;
				
							FILE *fptr_flag_baru;
							fptr_flag_baru = fopen("Data Pemilik Kos/flag_data_pemilik_kos_update.txt","r");
					
					for(j = 0; j < index; j++){
						if(fptr_flag_baru==NULL){
							fprintf(Tipe_baru,"%d %lld %d %.2f %.2f %.2f %d", ArrayKos[j].tipe, ArrayKos[j].harga, ArrayKos[j].fasilitas, ArrayKos[j].PanjangKamar, ArrayKos[j].LebarKamar, ArrayKos[j].LuasKamar, ArrayKos[j].IdKos);
												
						}
						else{
							fprintf(Tipe_baru,"\n%d %lld %d %.2f %.2f %.2f %d", ArrayKos[j].tipe, ArrayKos[j].harga, ArrayKos[j].fasilitas, ArrayKos[j].PanjangKamar, ArrayKos[j].LebarKamar, ArrayKos[j].LuasKamar, ArrayKos[j].IdKos);
														
						}
					}
					fclose(fptr_flag_baru);
					printf("\n\t\t\t\t Data Telah Tersimpan\n\n");			
					fclose(Tipe_baru);
					remove("Data Pemilik Kos/Ummik_Kos.txt");
					rename("Data Pemilik Kos/Update_Ummik_Kos.txt", "Data Pemilik Kos/Ummik_Kos.txt");
				}
				
				else if(pilih_update == 3){
					FILE *Harga_baru;
					Harga_baru = fopen("Data Pemilik Kos/Update_Ummik_Kos.txt","w");
					printf("\n\t\t\t\tMasukkan Harga Kos baru = ");
					scanf("%lld", &Update[i].harga);
					ArrayKos[i].harga = Update[i].harga;
				
							FILE *fptr_flag_baru;
							fptr_flag_baru = fopen("Data Pemilik Kos/flag_data_pemilik_kos_update.txt","r");
					
					for(j = 0; j < index; j++){
						if(fptr_flag_baru==NULL){
							fprintf(Harga_baru,"%d %lld %d %.2f %.2f %.2f %d", ArrayKos[j].tipe, ArrayKos[j].harga, ArrayKos[j].fasilitas, ArrayKos[j].PanjangKamar, ArrayKos[j].LebarKamar, ArrayKos[j].LuasKamar, ArrayKos[j].IdKos);
												
						}
						else{
							fprintf(Harga_baru,"\n%d %lld %d %.2f %.2f %.2f %d", ArrayKos[j].tipe, ArrayKos[j].harga, ArrayKos[j].fasilitas, ArrayKos[j].PanjangKamar, ArrayKos[j].LebarKamar, ArrayKos[j].LuasKamar, ArrayKos[j].IdKos);
														
						}
					}
					fclose(fptr_flag_baru);
					printf("\n\t\t\t\t Data Telah Tersimpan\n\n");			
					fclose(Harga_baru);
					remove("Data Pemilik Kos/Ummik_Kos.txt");
					rename("Data Pemilik Kos/Update_Ummik_Kos.txt", "Data Pemilik Kos/Ummik_Kos.txt");
				}
				else if(pilih_update == 4){
					FILE *Fasilitas_baru;
					Fasilitas_baru = fopen("Data Pemilik Kos/Update_Ummik_Kos.txt","w");
					printf("\n\t\t\t\tMasukkan Harga Kos baru = ");
					scanf("%d", &Update[i].fasilitas);
					ArrayKos[i].fasilitas = Update[i].fasilitas;
				
							FILE *fptr_flag_baru;
							fptr_flag_baru = fopen("Data Pemilik Kos/flag_data_pemilik_kos_update.txt","r");
					
					for(j = 0; j < index; j++){
						if(fptr_flag_baru==NULL){
							fprintf(Fasilitas_baru,"%d %lld %d %.2f %.2f %.2f %d", ArrayKos[j].tipe, ArrayKos[j].harga, ArrayKos[j].fasilitas, ArrayKos[j].PanjangKamar, ArrayKos[j].LebarKamar, ArrayKos[j].LuasKamar, ArrayKos[j].IdKos);
												
						}
						else{
							fprintf(Fasilitas_baru,"\n%d %lld %d %.2f %.2f %.2f %d", ArrayKos[j].tipe, ArrayKos[j].harga, ArrayKos[j].fasilitas, ArrayKos[j].PanjangKamar, ArrayKos[j].LebarKamar, ArrayKos[j].LuasKamar, ArrayKos[j].IdKos);
														
						}
					}
					fclose(fptr_flag_baru);
					printf("\n\t\t\t\t Data Telah Tersimpan\n\n");			
					fclose(Fasilitas_baru);
					remove("Data Pemilik Kos/Ummik_Kos.txt");
					rename("Data Pemilik Kos/Update_Ummik_Kos.txt", "Data Pemilik Kos/Ummik_Kos.txt");
				}
				else if(pilih_update == 5){
					Penyewa_Kos();
					break;
				}
				else{
					puts("\t\t\t\t\tInputan salah! tolong inputkan dengan benar!");
					system("pause");
					goto ulangi_update;
				}
				
			}
		}
		
		if(flag==0){
				printf("\n\n\t\t\t\t\t........................................\n");
				printf("\t\t\t\t\t          DATA TIDAK DITEMUKAN!         \n");
				printf("\t\t\t\t\t........................................\n");
			}	
	}
						
	system("Pause");
	Pemilik_Kos();
}

//============Fungsi Pencarian Kos
void SewaCariKamar(){
	system("cls");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================            Laman ''Penyewa'' KOS di UMMIK KOS                  ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");
	
	ulang:
	int pilih;
	puts("\t\t\t ===================================");
	puts("\t\t\t ||  Pilih Filter Pencarian Kos   ||");
	puts("\t\t\t ===================================\n");
	printf("\t\t\t\t[1] Provinsi\n");
	printf("\n\t\t\t\t[2] Kabupaten\n");
	printf("\n\t\t\t\t[3] Tipe kos\n");
	printf("\n\t\t\t\t[4] Tutup aplikasi\n\n");
	printf("\n\n\t\t\t\tpilih salah satu = ");
	scanf("%d", &pilih);
	if(pilih==1){
		SewaCariKamarProvinsi();
	}
	else if(pilih==2){
		SewaCariKamarKabupaten();
	}
	else if(pilih==3){
		SewaCariKamarTipe();
	}
	else if(pilih==4){
		exit();
	}
	else{
		printf("tolong inputkan yang benar!\n");
		system("pause");
		goto ulang;
	}
}

void SewaCariKamarProvinsi(){
	int i=0;
	char CariProvinsiKos[50];
	char BandingDataArrayProvinsi[50];
	char BandingCariProvinsi[50];
	
	FILE *view_FlagTotalData;
	view_FlagTotalData = fopen("Data Pemilik Kos/flag_data_pemilik_kos.txt","r");
	fscanf(view_FlagTotalData,"%d", &total_data);
			
	FILE *view_int;
	FILE *view_string_provinsi;
	FILE *view_string_kabupaten;
	FILE *view_string_jalan;
	FILE *view_NamaPemilikKos;
			
	view_int = fopen("Data Pemilik Kos/Ummik_Kos.txt","r");
	view_string_provinsi = fopen("Data Pemilik Kos/data_pemilik_kos_string_provinsi.txt","r");
	view_string_kabupaten = fopen("Data Pemilik Kos/data_pemilik_kos_string_kabupaten.txt","r");
	view_string_jalan = fopen("Data Pemilik Kos/data_pemilik_kos_string_jalan.txt","r");
	view_NamaPemilikKos = fopen("Data Pemilik Kos/NamaPemilik.txt","r");
	
	system("cls");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================            Laman ''Penyewa'' KOS di UMMIK KOS                  ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");
			
	if(view_int==NULL)
	{
		printf("\n\n\n");
		puts("\t\t\t ===============================");
		puts("\t\t\t ||     Belum ada data KOS    ||");
		puts("\t\t\t ===============================\n");
	}
	
	else
	{
		while(!feof(view_int))
		{
			fflush(stdin);
						
			fscanf(view_int,"%d %lld %d %f %f %f %d", &ArrayKos[i].tipe, &ArrayKos[i].harga, &ArrayKos[i].fasilitas, &ArrayKos[i].PanjangKamar, &ArrayKos[i].LebarKamar, &ArrayKos[i].LuasKamar, &ArrayKos[i].IdKos);
			fflush(stdin);
							
			fscanf(view_string_provinsi," %[^\n]s", &ArrayKos[i].lokasi.provinsi);
		    fscanf(view_string_kabupaten," %[^\n]s", &ArrayKos[i].lokasi.Kabupaten);
		    fscanf(view_string_jalan," %[^\n]s", &ArrayKos[i].lokasi.jalan);
		    fscanf(view_NamaPemilikKos," %[^\n]s", &ArrayKos[i].NamaPemilikKos);
			i++;
		}
			
		fclose(view_FlagTotalData);
		fclose(view_string_provinsi);
		fclose(view_int);
		fclose(view_string_kabupaten);
		fclose(view_string_jalan);
		fclose(view_NamaPemilikKos);
							
		
		printf("\n\t\t\t\t\t=================== Pencarian kos Berdasarkan Provinsi ==================\n\n");
		
		fflush(stdin);		
		printf("\n\t\t\t\tProvinsi bagian mana yang ingin dicari? ");
		scanf(" %[^\n]s", &CariProvinsiKos);
		
		SelectionSort_Asc();
		
		int flag = 0;
		for(i=0;i<total_data;i++)
		{

			if( strcmp(CariProvinsiKos,ArrayKos[i].lokasi.provinsi) == 0 ){
				printf("========================================================================================================================================================================\n");
		        printf("|| \tID Kos\t: %d \n", ArrayKos[i].IdKos);
				printf("|| \tNama Pemilik\t: %s \n", ArrayKos[i].NamaPemilikKos);
		        printf("|| \tTipe Kos \t: %d (1. Laki-laki ; 2. Perempuan ; 3. Campuran (wajib Mahrom)) \n", ArrayKos[i].tipe);
		        printf("|| \tAlamat \t\t: Prov. %s, Kab. %s, Jalan %s \n", ArrayKos[i].lokasi.provinsi, ArrayKos[i].lokasi.Kabupaten, ArrayKos[i].lokasi.jalan);
		        printf("|| \tFasilitas \t: %d\n", Kos.fasilitas);
		        printf("|| \tLuas \t\t: %.2f m2 (%.2f x %.2f)m \n", ArrayKos[i].LuasKamar, ArrayKos[i].PanjangKamar, ArrayKos[i].LebarKamar);
		        printf("|| \tHarga \t\t: %lld\n", ArrayKos[i].harga);
				flag = 1;
				}
		}
			printf("========================================================================================================================================================================\n\n\n");
	   		printf("========================================================================================================================================================================\n");
   			printf("|| \t KETERANGAN FASILITAS\n");
   			printf("|| \t\t\t[1] Wifi\n");
			printf("|| \t\t\t[2] Kamar Mandi dalam\n");
			printf("|| \t\t\t[3] AC\n");
			printf("|| \t\t\t[4] 2 diantara 3 pilihan diatas\n");
			printf("|| \t\t\t[5] Lengkap!\n");
   			printf("========================================================================================================================================================================\n");

			if(flag==0){
				printf("\n\n\t\t\t\t\t........................................\n");
				printf("\t\t\t\t\t          DATA TIDAK DITEMUKAN!         \n");
				printf("\t\t\t\t\t........................................\n");
			}
    }
    system("Pause");
	Penyewa_Kos();
}

void SewaCariKamarKabupaten(){
	int i=0;
	char CariKabupatenKos[50];
	
	FILE *view_FlagTotalData;
	view_FlagTotalData = fopen("Data Pemilik Kos/flag_data_pemilik_kos.txt","r");
	fscanf(view_FlagTotalData,"%d", &total_data);
			
	FILE *view_int;
	FILE *view_string_provinsi;
	FILE *view_string_kabupaten;
	FILE *view_string_jalan;
	FILE *view_NamaPemilikKos;
			
	view_int = fopen("Data Pemilik Kos/Ummik_Kos.txt","r");
	view_string_provinsi = fopen("Data Pemilik Kos/data_pemilik_kos_string_provinsi.txt","r");
	view_string_kabupaten = fopen("Data Pemilik Kos/data_pemilik_kos_string_kabupaten.txt","r");
	view_string_jalan = fopen("Data Pemilik Kos/data_pemilik_kos_string_jalan.txt","r");
	view_NamaPemilikKos = fopen("Data Pemilik Kos/NamaPemilik.txt","r");
	
	system("cls");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================            Laman ''Penyewa'' KOS di UMMIK KOS                  ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");

			
	if(view_int==NULL)
	{
		
		printf("\n\n\n");
		puts("\t\t\t ===============================");
		puts("\t\t\t ||     Belum ada data KOS    ||");
		puts("\t\t\t ===============================\n");
	}
	
	else
	{
		while(!feof(view_int))
		{
			fflush(stdin);
						
			fscanf(view_int,"%d %lld %d %f %f %f %d", &ArrayKos[i].tipe, &ArrayKos[i].harga, &ArrayKos[i].fasilitas, &ArrayKos[i].PanjangKamar, &ArrayKos[i].LebarKamar, &ArrayKos[i].LuasKamar, &ArrayKos[i].IdKos);
			fflush(stdin);
							
			fscanf(view_string_provinsi," %[^\n]s", &ArrayKos[i].lokasi.provinsi);
		    fscanf(view_string_kabupaten," %[^\n]s", &ArrayKos[i].lokasi.Kabupaten);
		    fscanf(view_string_jalan," %[^\n]s", &ArrayKos[i].lokasi.jalan);
		    fscanf(view_NamaPemilikKos," %[^\n]s", &ArrayKos[i].NamaPemilikKos);
			i++;
		}
			
		fclose(view_FlagTotalData);
		fclose(view_string_provinsi);
		fclose(view_int);
		fclose(view_string_kabupaten);
		fclose(view_string_jalan);
		fclose(view_NamaPemilikKos);
							
		
		printf("\n\t\t\t\t\t=================== Pencarian kos Berdasarkan Kabupaten ==================\n\n");
		
		fflush(stdin);		
		printf("\n\t\t\tKabupaten bagian mana yang ingin dicari = ");
		scanf(" %[^\n]s", &CariKabupatenKos);
		
		SelectionSort_Asc();
		
		int flag = 0;
		for(i=0;i<total_data;i++)
		{

			if( strcmp(CariKabupatenKos,ArrayKos[i].lokasi.Kabupaten) == 0 ){
				printf("========================================================================================================================================================================\n");
		        printf("|| \tID Kos\t: %d \n", ArrayKos[i].IdKos);
				printf("|| \tNama Pemilik\t: %s \n", ArrayKos[i].NamaPemilikKos);
		        printf("|| \tTipe Kos \t: %d (1. Laki-laki ; 2. Perempuan; 3. Campuran (wajib Mahrom)) \n", ArrayKos[i].tipe);
		        printf("|| \tAlamat \t\t: Prov. %s, Kab. %s, Jalan %s \n", ArrayKos[i].lokasi.provinsi, ArrayKos[i].lokasi.Kabupaten, ArrayKos[i].lokasi.jalan);
		        printf("|| \tFasilitas \t: %d\n", Kos.fasilitas);
		        printf("|| \tLuas \t\t: %.2f m2 (%.2f x %.2f)m \n", ArrayKos[i].LuasKamar, ArrayKos[i].PanjangKamar, ArrayKos[i].LebarKamar);
		        printf("|| \tHarga \t\t: %lld\n", ArrayKos[i].harga);
				flag = 1;
				}
		}
			printf("========================================================================================================================================================================\n\n\n");
	   		printf("========================================================================================================================================================================\n");
   			printf("|| \t KETERANGAN FASILITAS\n");
   			printf("|| \t\t\t[1] Wifi\n");
			printf("|| \t\t\t[2] Kamar Mandi dalam\n");
			printf("|| \t\t\t[3] AC\n");
			printf("|| \t\t\t[4] 2 diantara 3 pilihan diatas\n");
			printf("|| \t\t\t[5] Lengkap!\n");
   			printf("========================================================================================================================================================================\n");

			if(flag==0){
				printf("\n\n\t\t\t\t\t........................................\n");
				printf("\t\t\t\t\t          DATA TIDAK DITEMUKAN!         \n");
				printf("\t\t\t\t\t........................................\n");
			}
    	}
    system("Pause");
	Penyewa_Kos();
}


void SewaCariKamarTipe(){
	int i=0;
	int CariTipeKos;
	
	FILE *view_FlagTotalData;
	view_FlagTotalData = fopen("Data Pemilik Kos/flag_data_pemilik_kos.txt","r");
	fscanf(view_FlagTotalData,"%d", &total_data);
	
	FILE *view_int;
	FILE *view_string_provinsi;
	FILE *view_string_kabupaten;
	FILE *view_string_jalan;
	FILE *view_NamaPemilikKos;
			
	view_int = fopen("Data Pemilik Kos/Ummik_Kos.txt","r");
	view_string_provinsi = fopen("Data Pemilik Kos/data_pemilik_kos_string_provinsi.txt","r");
	view_string_kabupaten = fopen("Data Pemilik Kos/data_pemilik_kos_string_kabupaten.txt","r");
	view_string_jalan = fopen("Data Pemilik Kos/data_pemilik_kos_string_jalan.txt","r");
	view_NamaPemilikKos = fopen("Data Pemilik Kos/NamaPemilik.txt","r");
	
	system("cls");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================            Laman ''Penyewa'' KOS di UMMIK KOS                  ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");

			
	if(view_int==NULL)
	{
	
		printf("\n\n\n");
		puts("\t\t\t ===============================");
		puts("\t\t\t ||     Belum ada data KOS    ||");
		puts("\t\t\t ===============================\n");
	}
	
	else
	{
			
		while(!feof(view_int))
		{
			fflush(stdin);
						
			fscanf(view_int,"%d %lld %d %f %f %f %d", &ArrayKos[i].tipe, &ArrayKos[i].harga, &ArrayKos[i].fasilitas, &ArrayKos[i].PanjangKamar, &ArrayKos[i].LebarKamar, &ArrayKos[i].LuasKamar, &ArrayKos[i].IdKos);
			fflush(stdin);
							
			fscanf(view_string_provinsi," %[^\n]s", &ArrayKos[i].lokasi.provinsi);
		    fscanf(view_string_kabupaten," %[^\n]s", &ArrayKos[i].lokasi.Kabupaten);
		    fscanf(view_string_jalan," %[^\n]s", &ArrayKos[i].lokasi.jalan);
		    fscanf(view_NamaPemilikKos," %[^\n]s", &ArrayKos[i].NamaPemilikKos);
			i++;
		}
			
		fclose(view_FlagTotalData);
		fclose(view_string_provinsi);
		fclose(view_int);
		fclose(view_string_kabupaten);
		fclose(view_string_jalan);
		fclose(view_NamaPemilikKos);
							
		printf("\n\t\t\t\t\t=================== Pencarian kos Berdasarkan tipe ==================\n\n");
				
		printf("\n\t\t\t\t\tMasukkan tipe kos yang ingin dicari: ");
		puts("\n\n\n\t\t\t\t[1]. Putra");
		puts("\n\t\t\t\t[2]. Putri");
		puts("\n\t\t\t\t[3]. Campuran(wajib melampirkan KK)");
		printf("\n\n\t\t\t\t\tpilih salah satu = ");
		scanf("%d", &CariTipeKos);
			
		SelectionSort_Asc();
			
		int flag = 0;
		for(i=0;i<total_data;i++)
		{
			if(CariTipeKos == ArrayKos[i].tipe){
				printf("========================================================================================================================================================================\n");
		        printf("|| \tID Kos\t: %d \n", ArrayKos[i].IdKos);
				printf("|| \tNama Pemilik\t: %s \n", ArrayKos[i].NamaPemilikKos);
		        printf("|| \tTipe Kos \t: %d (1. Laki-laki ; 2. Perempuan ; 3. Campuran (wajib Mahrom)) \n", ArrayKos[i].tipe);
		        printf("|| \tAlamat \t\t: Prov. %s, Kab. %s, Jalan %s \n", ArrayKos[i].lokasi.provinsi, ArrayKos[i].lokasi.Kabupaten, ArrayKos[i].lokasi.jalan);
		        printf("|| \tFasilitas \t: %d\n", Kos.fasilitas);
		        printf("|| \tLuas \t\t: %.2f m2 (%.2f x %.2f)m \n", ArrayKos[i].LuasKamar, ArrayKos[i].PanjangKamar, ArrayKos[i].LebarKamar);
		        printf("|| \tHarga \t\t: %lld\n", ArrayKos[i].harga);
				flag = 1;
				}
		}
			printf("========================================================================================================================================================================\n\n\n");
	   		printf("========================================================================================================================================================================\n");
   			printf("|| \t KETERANGAN FASILITAS\n");
   			printf("|| \t\t\t[1] Wifi\n");
			printf("|| \t\t\t[2] Kamar Mandi dalam\n");
			printf("|| \t\t\t[3] AC\n");
			printf("|| \t\t\t[4] 2 diantara 3 pilihan diatas\n");
			printf("|| \t\t\t[5] Lengkap!\n");
   			printf("========================================================================================================================================================================\n");

			if(flag==0){
				printf("\n\n\t\t\t\t\t........................................\n");
				printf("\t\t\t\t\t          DATA TIDAK DITEMUKAN!         \n");
				printf("\t\t\t\t\t........................................\n");
			}
    	}
    		ulang_disini:
			int pilih_ulang;
			printf("\n\t\t\t\t[1]Menu Utama\n\n\t\t\t\t[2]Laman Penyewa Kos\n\n\t\t\t\t[3]Keluar\n\n\t\t\t\t\t\tPilih salah satu  : ");
			scanf("%d", &pilih_ulang);
			if(pilih_ulang==1){
				mainMenu();	
			}
			else if(pilih_ulang==2){
				Penyewa_Kos();
			}
			else if(pilih_ulang==3){
				exit();
			}	
			else{
				printf("\ntolong inputkan angka antara [1]/[2]/[3]\n");
				system("pause");
				goto ulang_disini;
			}
	system("Pause");
	Penyewa_Kos();
}


void tukar(struct pemilik_kos *x, struct pemilik_kos *y){
	struct pemilik_kos t = *x;
	*x = *y;
	*y = t;
}

void SelectionSort_Asc(){
	int Index_Nilai_Terkecil, current_Index=0;
	for(int q=0;q<total_data-1;q++){
		Index_Nilai_Terkecil=q;
		for(int w=q+1;w<total_data;w++){
			if(ArrayKos[Index_Nilai_Terkecil].harga>ArrayKos[w].harga){
				Index_Nilai_Terkecil = w;	
			}
		}
		tukar(&ArrayKos[Index_Nilai_Terkecil], &ArrayKos[current_Index]);
		current_Index++;
	}
}

void SelectionSort_Dsc(){
	int Index_Nilai_Terkecil, current_Index=0;
	for(int q=0;q<total_data-1;q++){
		Index_Nilai_Terkecil=q;
		for(int w=q+1;w<total_data;w++){
			if(ArrayKos[Index_Nilai_Terkecil].harga<ArrayKos[w].harga){
				Index_Nilai_Terkecil = w;	
			}
		}
		tukar(&ArrayKos[Index_Nilai_Terkecil], &ArrayKos[current_Index]);
		current_Index++;
	}
}


void input_kos(){
	fflush(stdin);
	system("cls");
	printf("\n\n\t\t\t\t\t===== Masukkan inputan dibawah ini =====\n");
	printf("\t\t\t\t\t........................................\n");
	printf("\t\t\t\t\t=========== Nama pemilik Kos ===========\n");
	printf("\t\t\t\t\tNama anda adalah :");
	scanf(" %[^\n]s", &Kos.NamaPemilikKos);
		
	ulangi_tipe:
	system("cls");
	printf("\n\n\t\t\t\t\t===== Masukkan inputan dibawah ini =====\n");
	printf("\t\t\t\t\t........................................\n");
	printf("\t\t\t\t\t=============== Tipe Kos ===============\n");
	printf("\n\t\t\t\t\t[1]Putra\n");
	printf("\n\t\t\t\t\t[2]Putri\n");
	printf("\n\t\t\t\t\t[3]Campur(Wajib mahram)\n");
	printf("\n\t\t\t\t\tPilih salah satu [1/2/3] = ");
	scanf("%d", &Kos.tipe);
	
	if(Kos.tipe!=1&&Kos.tipe!=2&&Kos.tipe!=3){
		puts("\t\t\t\t\tInputan salah! tolong inputkan dengan benar!");
		system("pause");
		goto ulangi_tipe;
	}
	
	system("cls");
	printf("\n\n\t\t\t\t\t===== Masukkan inputan dibawah ini =====\n");
	printf("\t\t\t\t\t........................................\n");
	printf("\t\t\t\t\t============== Alamat Kos ==============\n");
	printf("\n\t\t\t\t\tMasukkan Alamat:");
	printf("\n\t\t\t\t\t\tProvinsi = ");
	scanf(" %[^\n]s", &Kos.lokasi.provinsi);
	printf("\n\t\t\t\t\t\tKabupaten = ");
	scanf(" %[^\n]s", &Kos.lokasi.Kabupaten);
	printf("\n\t\t\t\t\t\tJalan = ");
	scanf(" %[^\n]s", &Kos.lokasi.jalan);
	
	system("cls");
	printf("\n\n\t\t\t\t\t===== Masukkan inputan dibawah ini =====\n");
	printf("\t\t\t\t\t........................................\n");
	printf("\n\t\t\t\t\t========= Harga Kos per Bulan ========\n");
	printf("\n\t\t\t\t\tHarga = ");
	scanf("%lld", &Kos.harga);
	
	ulangi_fasilitas:
	system("cls");
	printf("\n\n\t\t\t\t\t===== Masukkan inputan dibawah ini =====\n");
	printf("\t\t\t\t\t........................................\n");
	printf("\n\t\t\t\t\t============ Fasilitas Kos ===========\n");
	printf("\n\t\t\t\t\t[1] Wifi\n");
	printf("\n\t\t\t\t\t[2] Kamar Mandi dalam\n");
	printf("\n\t\t\t\t\t[3] AC\n");
	printf("\n\t\t\t\t\t[4] 2 diantara 3 pilihan diatas\n");
	printf("\n\t\t\t\t\t[5] Lengkap!\n");
	printf("\n\t\t\t\t\tPilih salah satu [1/2/3/4/5] = ");
	scanf("%d", &Kos.fasilitas);
	if(Kos.fasilitas!=1&&Kos.fasilitas!=2&&Kos.fasilitas!=3&&Kos.fasilitas!=4&&Kos.fasilitas!=5){
		puts("\t\t\t\t\tInputan salah! tolong inputkan dengan benar!");
		system("pause");
		goto ulangi_fasilitas;
	}
	
	system("cls");
	printf("\n\n\t\t\t\t\t===== Masukkan inputan dibawah ini =====\n");
	printf("\t\t\t\t\t........................................\n");
	printf("\n\t\t\t\t\t============== Ukuran Kos ============\n");
	printf("\n\t\t\t\t\tHARUS gunakan simbol (.)/TITIK untuk koma");
	printf("\n\t\t\t\t\tLebar Kos : ");
	scanf("%f", &Kos.LebarKamar);
	printf("\n\t\t\t\t\tPanjang Kos :");
	scanf("%f", &Kos.PanjangKamar);
	
	Kos.LuasKamar = Kos.PanjangKamar * Kos.LebarKamar;
	printf("\n\n\t\t\t\t\tLuas Kos : %.2f", Kos.LuasKamar);
	
	
	printf("\n\t\t\t\t\t........................................\n");
	
	FILE *fptr_flag;
	fptr_flag = fopen("Data Pemilik Kos/flag_data_pemilik_kos.txt","r");
		
	FILE *fptr;
	FILE *fptr_string_provinsi, *fptr_string_kabupaten, *fptr_string_jalan;
	FILE *fptr_NamaPemilikKos;
	
	fptr = fopen("Data Pemilik Kos/Ummik_Kos.txt","a"); //menghasilkan pointer
	fptr_string_provinsi = fopen("Data Pemilik Kos/data_pemilik_kos_string_provinsi.txt","a");
	fptr_string_kabupaten = fopen("Data Pemilik Kos/data_pemilik_kos_string_kabupaten.txt","a");
	fptr_string_jalan = fopen("Data Pemilik Kos/data_pemilik_kos_string_jalan.txt","a");
	fptr_NamaPemilikKos = fopen("Data Pemilik Kos/NamaPemilik.txt","a");
	
	if(fptr_flag==NULL){
		fprintf(fptr,"%d %lld %d %.2f %.2f %.2f", Kos.tipe, Kos.harga, Kos.fasilitas, Kos.PanjangKamar, Kos.LebarKamar, Kos.LuasKamar);	
		fputs(Kos.lokasi.provinsi, fptr_string_provinsi);

		fputs(Kos.lokasi.Kabupaten, fptr_string_kabupaten);

		fputs(Kos.lokasi.jalan, fptr_string_jalan);	
		
		fputs(Kos.NamaPemilikKos, fptr_NamaPemilikKos);
		
	}
	else{
		fprintf(fptr,"\n%d %lld %d %.2f %.2f %.2f", Kos.tipe, Kos.harga, Kos.fasilitas, Kos.PanjangKamar, Kos.LebarKamar, Kos.LuasKamar);	
		
		fputs("\n", fptr_string_provinsi);
		fputs("\n", fptr_string_kabupaten);
		fputs("\n", fptr_string_jalan);
		fputs("\n", fptr_NamaPemilikKos);
		
		fputs(Kos.lokasi.provinsi, fptr_string_provinsi);

		fputs(Kos.lokasi.Kabupaten, fptr_string_kabupaten);

		fputs(Kos.lokasi.jalan, fptr_string_jalan);
		
		fputs(Kos.NamaPemilikKos, fptr_NamaPemilikKos);
		
		fscanf(fptr_flag,"%d", &total_data);
		
	}
	
	fclose(fptr);
	fclose(fptr_flag);
	fclose(fptr_string_provinsi);
	fclose(fptr_string_kabupaten);
	fclose(fptr_string_jalan);
	fclose(fptr_NamaPemilikKos);
	
	fptr_flag = fopen("Data Pemilik Kos/flag_data_pemilik_kos.txt","w");
	total_data++;
	fprintf(fptr_flag,"%d",total_data);
	fclose(fptr_flag);
	
	Kos.IdKos = total_data;
	
	fptr =  fopen("Data Pemilik Kos/Ummik_Kos.txt","a");
	fprintf(fptr," %d", Kos.IdKos);
	fclose(fptr);
	
	puts("\t\t\t ===============================");
	puts("\t\t\t ||    Data telah tersimpan   ||");
	puts("\t\t\t ===============================\n");
	system("pause");
	Pemilik_Kos();
}


void lihat_kos(){
	system("cls");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================                 Lihat Daftar KOS di UMMIK KOS                  ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");
	int pilih;
	char buff[500];
	FILE *view_int;
	FILE *view_string_provinsi;
	FILE *view_string_kabupaten;
	FILE *view_string_jalan;
	FILE *view_NamaPemilikKos;
	
	view_int = fopen("Data Pemilik Kos/Ummik_Kos.txt","r");
	view_string_provinsi = fopen("Data Pemilik Kos/data_pemilik_kos_string_provinsi.txt","r");
	view_string_kabupaten = fopen("Data Pemilik Kos/data_pemilik_kos_string_kabupaten.txt","r");
	view_string_jalan = fopen("Data Pemilik Kos/data_pemilik_kos_string_jalan.txt","r");
	view_NamaPemilikKos = fopen("Data Pemilik Kos/NamaPemilik.txt","r");
	
	if(view_int==NULL&&view_string_provinsi==NULL){
		puts("\t\t\t ===============================");
		puts("\t\t\t ||     Belum ada data KOS    ||");
		puts("\t\t\t ===============================\n");
	}
	else{
		while(!feof(view_int)){
				fflush(stdin);
				fscanf(view_int,"%d %lld %d %f %f %f %d", &Kos.tipe, &Kos.harga, &Kos.fasilitas, &Kos.PanjangKamar, &Kos.LebarKamar, &Kos.LuasKamar, &Kos.IdKos);
				fflush(stdin);
				
				fscanf(view_string_provinsi," %[^\n]s", &Kos.lokasi.provinsi);
		        fscanf(view_string_kabupaten," %[^\n]s", &Kos.lokasi.Kabupaten);
		        fscanf(view_string_jalan," %[^\n]s", &Kos.lokasi.jalan);
		        fscanf(view_NamaPemilikKos," %[^\n]s", &Kos.NamaPemilikKos);
		        fflush(stdin);
		        
		        printf("========================================================================================================================================================================\n");
		        printf("|| \tID Kos\t: %d \n", Kos.IdKos);
				printf("|| \tNama Pemilik\t: %s \n", Kos.NamaPemilikKos);
		        printf("|| \tTipe Kos \t: %d (1. Laki-laki ; 2. Perempuan ; 3. Campuran (wajib Mahrom)) \n", Kos.tipe);
		        printf("|| \tAlamat \t\t: Prov. %s, Kab. %s, Jalan %s \n", Kos.lokasi.provinsi, Kos.lokasi.Kabupaten, Kos.lokasi.jalan);
		        printf("|| \tFasilitas \t: %d\n", Kos.fasilitas);
		        printf("|| \tLuas \t\t: %.2f m2 (%.2f x %.2f)m \n", Kos.LuasKamar, Kos.PanjangKamar, Kos.LebarKamar);
		        printf("|| \tHarga \t\t: %lld\n", Kos.harga);
				
   		}
   		printf("========================================================================================================================================================================\n\n\n");
   		printf("========================================================================================================================================================================\n");
   		printf("|| \t KETERANGAN FASILITAS\n");
   		printf("|| \t\t\t[1] Wifi\n");
		printf("|| \t\t\t[2] Kamar Mandi dalam\n");
		printf("|| \t\t\t[3] AC\n");
		printf("|| \t\t\t[4] 2 diantara 3 pilihan diatas\n");
		printf("|| \t\t\t[5] Lengkap!\n");
   		printf("========================================================================================================================================================================\n");
	}
		FILE *view_TotalKos;
		view_TotalKos = fopen("Data Pemilik Kos/flag_data_pemilik_kos.txt","r");
		fscanf(view_TotalKos,"%d",&total_data);
		printf("\n\n");
		printf("\t\t\t ===============================\n");
		printf("\t\t\t ||     jumlah banyak kos %d   ||\n ", total_data);
		printf("\t\t\t ===============================\n\n");
//	printf("\t\t\t\t\n\njumlah banyak kos %d\n", jumlah_kos);
	fclose(view_int);
	fclose(view_string_provinsi);
	fclose(view_string_kabupaten);
	fclose(view_string_jalan);
	fclose(view_NamaPemilikKos);
	
	ulang_disini:
	printf("\n\t\t\t\t[1]Menu Utama\n\n\t\t\t\t[2]Laman Pemilik Kos\n\n\t\t\t\t[3]Keluar\n\n\t\t\t\t\t\tPilih salah satu  : ");
	switch(getch()){
		case '1':
			mainMenu();
		break;
		case '2':
			Pemilik_Kos();
		break;
		case '3':
			exit();
		break;
		default:
			printf("\ntolong inputkan angka antara [1]/[2]/[3]\n");
			system("pause");
			goto ulang_disini;
	}
}


void lihat_kos_UIpenyewa(){
	system("cls");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================                 Lihat Daftar KOS di UMMIK KOS                  ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");
	int pilih;
	char buff[500];
	FILE *view_int;
	FILE *view_string_provinsi;
	FILE *view_string_kabupaten;
	FILE *view_string_jalan;
	FILE *view_NamaPemilikKos;
	
	view_int = fopen("Data Pemilik Kos/Ummik_Kos.txt","r");
	view_string_provinsi = fopen("Data Pemilik Kos/data_pemilik_kos_string_provinsi.txt","r");
	view_string_kabupaten = fopen("Data Pemilik Kos/data_pemilik_kos_string_kabupaten.txt","r");
	view_string_jalan = fopen("Data Pemilik Kos/data_pemilik_kos_string_jalan.txt","r");
	view_NamaPemilikKos = fopen("Data Pemilik Kos/NamaPemilik.txt","r");
	
	if(view_int==NULL&&view_string_provinsi==NULL){
		puts("\t\t\t ===============================");
		puts("\t\t\t ||     Belum ada data KOS    ||");
		puts("\t\t\t ===============================\n");
	}
	else{
		while(!feof(view_int)){
				fflush(stdin);
				fscanf(view_int,"%d %lld %d %f %f %f %d", &Kos.tipe, &Kos.harga, &Kos.fasilitas, &Kos.PanjangKamar, &Kos.LebarKamar, &Kos.LuasKamar, &Kos.IdKos);
				fflush(stdin);
				
				fscanf(view_string_provinsi," %[^\n]s", &Kos.lokasi.provinsi);
		        fscanf(view_string_kabupaten," %[^\n]s", &Kos.lokasi.Kabupaten);
		        fscanf(view_string_jalan," %[^\n]s", &Kos.lokasi.jalan);
		        fscanf(view_NamaPemilikKos," %[^\n]s", &Kos.NamaPemilikKos);
		        fflush(stdin);
		        
		        printf("========================================================================================================================================================================\n");
		        printf("|| \tID Kos\t: %d \n", Kos.IdKos);
				printf("|| \tNama Pemilik\t: %s \n", Kos.NamaPemilikKos);
		        printf("|| \tTipe Kos \t: %d (1. Laki-laki ; 2. Perempuan ; 3. Campuran (wajib Mahrom)) \n", Kos.tipe);
		        printf("|| \tAlamat \t\t: Prov. %s, Kab. %s, Jalan %s \n", Kos.lokasi.provinsi, Kos.lokasi.Kabupaten, Kos.lokasi.jalan);
		        printf("|| \tFasilitas \t: %d\n", Kos.fasilitas);
		        printf("|| \tLuas \t\t: %.2f m2 (%.2f x %.2f)m \n", Kos.LuasKamar, Kos.PanjangKamar, Kos.LebarKamar);
		        printf("|| \tHarga \t\t: %lld\n", Kos.harga);
				
   		}
   		printf("========================================================================================================================================================================\n\n\n");
   		printf("========================================================================================================================================================================\n");
   		printf("|| \t KETERANGAN FASILITAS\n");
   		printf("|| \t\t\t[1] Wifi\n");
		printf("|| \t\t\t[2] Kamar Mandi dalam\n");
		printf("|| \t\t\t[3] AC\n");
		printf("|| \t\t\t[4] 2 diantara 3 pilihan diatas\n");
		printf("|| \t\t\t[5] Lengkap!\n");
   		printf("========================================================================================================================================================================\n");
	}
		FILE *view_TotalKos;
		view_TotalKos = fopen("Data Pemilik Kos/flag_data_pemilik_kos.txt","r");
		fscanf(view_TotalKos,"%d",&total_data);
		printf("\n\n");
		printf("\t\t\t ===============================\n");
		printf("\t\t\t ||     jumlah banyak kos %d   ||\n ", total_data);
		printf("\t\t\t ===============================\n\n");
//	printf("\t\t\t\t\n\njumlah banyak kos %d\n", jumlah_kos);
	fclose(view_int);
	fclose(view_string_provinsi);
	fclose(view_string_kabupaten);
	fclose(view_string_jalan);
	fclose(view_NamaPemilikKos);
	
	ulang_disini:
	printf("\n\t\t\t\t[1]Menu Utama\n\n\t\t\t\t[2]Laman Penyewa Kos\n\n\t\t\t\t[3]Keluar\n\n\t\t\t\t\t\tPilih salah satu  : ");
	switch(getch()){
		case '1':
			mainMenu();
		break;
		case '2':
			Penyewa_Kos();
		break;
		case '3':
			exit();
		break;
		default:
			printf("\ntolong inputkan angka antara [1]/[2]/[3]\n");
			system("pause");
			goto ulang_disini;
	}
}

int main(){
	fullscreen();
	mainMenu();
	return 0;
}
