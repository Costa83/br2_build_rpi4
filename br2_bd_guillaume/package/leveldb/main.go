/* InfluxDB test  : Insertion de N rows */ 
/* go mod init test_influxdb
/ go mod tidy */



package main

import (
    "fmt"
    "test_leveldb/measuretime"
    "test_leveldb/leveldb"
    "time"
)

func main() {


  path := "testleveldb"
  lignes := "1"
  rows := "1000000"

  fmt.Printf("PROGRAMME DE TEST DE LEVELDB EN GO")
  fmt.Printf("## path : %s",path)
  fmt.Printf("## lignes : %s",lignes)
 

  /*Création de la base de donnée*/
  start  := time.Now()
  start = measuretime.Measuretime_start()
  fmt.Printf("Création de la base de donnée sur le chemin : %s  ", path )
  leveldb.Create_database_leveldb(path)
  measuretime.Measuretime_stop(start)
  
  /*Insertion de n lignes*/
  start = measuretime.Measuretime_start()
  
  leveldb.Write_database_leveldb(&rows, &path)
  measuretime.Measuretime_stop(start)
  
    
  
  /*
  Lecture de la database
  fmt.Printf("Lecture BD")
  start = measuretime.Measuretime_start()
  influxdb.Read_all_rows_database_influxdb(ip, port)
  measuretime.Measuretime_stop(start)
  
  Lecture de n éléments
  fmt.Printf("Lecture du nième élément")
  start = measuretime.Measuretime_start()
  influxdb.Read_one_row_database_influxdb(lignes, ip, port) 
  measuretime.Measuretime_stop(start)
  
  Supression du nième élément
  fmt.Printf("Suppression du nième élément")
  start = measuretime.Measuretime_start()
  influxdb.Delete_one_row_database_influxdb(lignes, ip, port) 
  measuretime.Measuretime_stop(start)
  
  Suppresion de la database
  fmt.Printf("Suppression DB")
  start = measuretime.Measuretime_start()
  influxdb.Delete_database_influxdb(ip, port)
  measuretime.Measuretime_stop(start)*/
  

}
