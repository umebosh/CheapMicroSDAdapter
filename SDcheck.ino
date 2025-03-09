#include <SPI.h>
#include <SD.h>  
#include <Arduino.h>

#define SD_CS_PIN 5   // CSピン
#define SPI_MISO 4   // MISO
#define SPI_MOSI 3   // MOSI
#define SPI_SCK  2   // SCK

void setup() {
    Serial.begin(115200); 
    while (!Serial) {
        ; 
    }
    Serial.println("Raspberry Pi Pico デバッグ開始");

    // SDカードの初期化
    checkSDCard();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void checkSDCard() {
    Serial.println("\n===== SDカードの確認 =====");

    // SDカードのSPIピン設定
    SPI.setSCK(SPI_SCK);
    SPI.setMOSI(SPI_MOSI);
    SPI.setMISO(SPI_MISO);
    SPI.begin();

    // SDカードの初期化
    if (!SD.begin(SD_CS_PIN)) {
        Serial.println("⚠️ SDカードの初期化に失敗しました");
        while (1); // エラー発生時は無限ループで停止
    }

    Serial.println("✅ SDカードが検出されました");
    Serial.println("SDカードの中身:");

    listFiles(SD.open("/"), 0);
}

// **SDカードのファイルリストを表示**
void listFiles(File dir, int level) {
    while (true) {
        File entry = dir.openNextFile();
        if (!entry) break; // すべてのファイルを取得したら終了

        // 隠しファイル (".xxx") を除外
        if (entry.name()[0] == '.') {
            entry.close();
            continue;
        }

        for (int i = 0; i < level; i++) Serial.print("  "); // インデント
        Serial.println(entry.name());

        if (entry.isDirectory()) {
            listFiles(entry, level + 1);
        }
        entry.close();
    }
}