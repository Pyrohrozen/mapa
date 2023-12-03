# Hledání cesty v terénní mapě

Máte zde připravený základ kódu pro práci s terénní mapou. Ta je reprezentována maticí 256x256 celých čísel představující nadmořskou výšku v metrech (soubor *terrain.dat*).

Najdete zde třídu *TerrainMap*, která obsahuje metody pro načtení mapy ze souboru a přístup k jednotlivým prvkům matice. Souřadnice můžete ukládat do objektů třídy *Point*, které podporují i některé vektorové operace. Dále můžete využít třídu *Matrix< >* pro reprezentaci libovolných pomocných maticových dat.

Dále je zde abstraktní třída *Path* která slouží k ukládání souřadnic jednotlivých bodů cesty do struktury vector<Point>, obsahuje dále metody pro analýzu cesty a výpis cesty do souboru. Předpokládáme, že se můžeme po mapě pohybovat vždy o 1 pole ve vodorovném, svislém a šikmém směru. Vaším úkolem bude vytvořit odvozené třídy s implementovanou metodou *find()* pro nalezení cest následujících typů:

- **"Letadlo"** - nejkratší cesta mezi dvěma body nehledě na nadmořskou výšku
- **"Loď"** - nejkratší cesta pouze po polích, kde výška < 0 (kromě výchozího a cílového bodu)
- **"Silnice"** - nejkratší cesta pouze po polích, kde výška > 0 a zároveň stoupání trasy mezi následujícími body < 0.6%
- **"Silnice + trajekt"** - nejrychlejší cesta mezi dvěma body
  - pokud je výška > 0, stoupání trasy mezi následujícími body musí být < 0.6%
  - pokud je výška < 0, stoupání není podstatné, ale rychlost pohybu je pouze čtvrtinová oproti pohybu na souši
- **"Nákladní železnice"** - cesta mezi dvěma body, která minimalizuje celkový součet výškových metrů (stoupání i klesání) na trase a zároveň stoupání trasy mezi následujícími body < 0.4%

Najděte tyto typy cest mezi body [198 205] a [78 17]

Funkce *main(...)* je vytvořena tak, že program přijímá jako vstup z příkazové řádky název souboru s mapou a souřadnice počátečního a koncového bodu, např.:
 	`./findpath terrain.dat 198 205 78 17`

Skript `./plot_path.py terrain.dat cesta.dat` vykreslí terénní mapu a do ní nalezenou cestu.
