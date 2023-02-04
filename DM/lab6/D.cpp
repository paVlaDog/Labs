#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;


/*
 *HHHHHHHBMBHBBBBBBMBHHHBHHBBBHHHHHHHHHHHHHHHHHHHHHHHHHBMBHHHHHHHHHHHHHHHHHHHHHHHHHBBHHHHHHHHHHHHHHHHHHHHHHHBBBB
HHHHHHHBMBBHHBBHBMBHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMHHHHHHHHHHHHHHHHHHHHHHHHHBHHHHHHHHHHHHHHHHHHHHHHHHBBBB
HHHHHHHBMBHHHBHHBMBHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHMMBHHHHHHBBHHHBBBBHBBBHHHHHBHHHHHHHHHHHHHHHHHHHHHHHHBBBB
HHHHHHHBMBHHBHHBBMBHHHHHHHHHHHHHHHHAHHHHHHHHHHHHHHHHHHMBHHHHHHHHHHHHHHHHHHBHHHHHHBBHHHHHHHHHHHHHHHHHHHHHHHBBBB
HHHHHHHBMBBBHHBHBMBHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHAAHMBHHHHHHHHHHHHHHHHHHHHHHHHHBBHHHHHHHHHHHHHHHHHHHHHHHBBBB
AHHHHHHBMBHHHHHBBBBHHHHHHHHHHHHHHHHHAHAHHHHHHHG&AA&&&&AHA&HHAHAHHHHHHHHHHHHHHHHHHBHHHHHHHHHHHHHHHHHHHHHHHBBBBB
HHHHHHHBMBBHHHHHBBHHHHHHHHHHHHHHHHHAHHHHAHHHA&Ghh9h99hhGhh99GGGG&AHHBHHHHHHHHHHHHBHHHHHHHHHHHHHHHHHHHHHHHHBBBH
HHHHHHHBMBHHHHHBBBBHHHHHHHHHHHHHHHHHAHHHA&Ghh93XXX2222XXXX9hh&&GAAAAHHHHHHHHHHHHHBHHHHHHHHHHHHHHHHHHHHHHHBBBBB
HHHHHHHBMBHHHHHBBBHAHHHHHHHHHHHHHHHHAAA&GG9XX22255555552X2XX339GG&9AAAAHHHBHHHHHHBHHHHHHHHHHHHHHHHHHHHHHHBBBBB
AHHHHHHBMBHHHHHBBBHAHHHHHHHHHHHHHHHAA&&hX225555SSSSSSSSS5522XX33XG&&9HHAHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHBBBBB
HHHHHHHBMBHHHHHBBBHHHHHHHHHHHHHHHHG&hG2555SSSSiiisiiiiiSSS5522XXXX9&GHHHAAHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHBBB
HAHHHHHHMBHHHHHBBBHHHHHHHHHHHHHHAhG&95SSSSiissssssssssiiiiS55222XXX9h&&A&&HHHHHHHBHHHHHHHHHHHHHHHHHHHHHHHHBBBB
HHHHHHHHMBHHHHHBBBHHHHHAHHHHHHH&G&G9SSSSiissssssrrrrsssiiiSSS5552XX2299GAGAAHHHHHBHAHHHHHHHHHHHHHHHHHHHHHBBBBB
AHHHHHHHMBHHHHBBBBHHHHHHHHHHHH&GhG3S5SSiissssrrrrrrrrrssssiiiS5522X322X3&&&AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHBBBBB
AHHHHHHBMBBHHHHBBBHHHHHHHHAHHAGh9XiSSSiissssrrrrrrrrrssssssiiiS5522XX52X39A&AHHHHBHHHHHHHHHHHHHHHHHHHHHHBBBBBB
HHHHHHHBMBBHHBHBBBHHHHHHHHHHHG93XSS5SSissrsrrrrr;rrrrrssssssiiSS52223XX2X39&&HHHHHHHHHHHHHHHHHHHHHHHHHHHBBBBBB
HHHHHHHBMBBHBBBBBBHHHHHHHHHHAhh2iSSSiisssrrrrr;;;;;;;;rrrrsssiiSSS5523XXX399AAAHHHHHHHHHHHHHHHHHHHHHHHHHHBBBBB
HHHHHHHHMMBHHBHBBBHHHHHHHHHHG33SSSSiissssrr;;;;;;:::;;;rrrrrssiiSSSS5XXXXXh99&AHHHHHHHHHHHHHHHHHHHHHHHHHBHBBBB
HHHHHHHHMMBHHHHBBBHHHHHHHHA&995SiiSissssrr;;;;::,,,:,:;;;rrrrsiiSSSS523XX33hh&HAHHHHHHHHHHHHHHHHHHHHHHHHHHBBBH
HHHHHHHBMBBHHHHBBBHAHHHHHHHGh35iiiiirrrrrr;;;::,,,,,,,:;;;rrrsisiiSS52XX3399&GHHHHHHHHHHHHHHHHHHHHHHHHHHHHBBBB
HHHHHHBHMMBBHHHBBHHHHHHHHHHhG35iiissrrrrr;;;;:,....,,,,:;;rrsssiiiSS55XX333GG&AHHHHHHHHHHHHHHHHHHHHHHHHHHBBBBB
AHHHHHHHMMBBBHBBHHHHHHHHHHH&G35Siissrrrr;;;;;:,,.,,,,,,,:;rrrssssiSiS5XXX39G&&HHHHHHHHHHHHHHHHHHHHHHHHHHHBBBBH
HHHHHHHHBMBBBHBHBHHHHHHHHHHGh92Sisssrrr;;;;;;::::;;;:,::::;rrrsrssSS52XX39hGGAHHHHHHHHHHHHHHHHHHHHHHHHHHHHBBBB
HHHHHHHHBMBBBBBHHHHAHHHHHHAGGhXSiissrrr;;;;:::,,:;;;;:::::;;;r;rrssi52XX339GG&H&&HHAHHHHHHHHHHHHHHHHHHHHHHHBBB
HHHHHHHHBMBBHBHBBHHHHHHHHHG&G93Siisssrr;;:::,,,,,,,,,,.,::::;;;rrsssi5X3X39G&H&3GhHHHHHHHHHHHHHHHHHHHHHHHHBBBB
AHHHHHHHBMBBBBHBBHHHHHHHHAHhGGXSiiisr;;;:;:::,,,,,,:,:::;;rrssiisssiSSX3339GAAGG&3HHHHHHHHHHHHHHHHHHHHHHHHBBBB
AHHHHHHHBMBBBBHBBBHHHHHHHH23hhXSisiisrrrrrsiiiisr;:::;;rssS239X55SSSS2X3X39hGGGh9XAAHHHHHHHHHHHHHHHHHHHHHHBBBB
HHHHHHHHBMBBBHHHHHHHHHHHHHiS995SisiSirsrsS552225isr;;rssS5X32SsS5S5XS5522X3hGGh39SHHHHHHHHHHHHHHHHHHHHHHHBBBBH
HHHHHHHHBMBBBHBHHBHAHHHHHHsiSX5Sissssss25i2X2S525Ssr;rsi29255,55AXiX35SsS29hGAGX2sGHHHHHHHHHHHBHHHHHHHHHHHBBHH
HHHHHHHHBMMBBHBBBHHHHHHHHHisii55issriS22iSGH2rs25iir;:sSXS2iSrrriiS52iisS59hGAGXS29HHHHHHHHHHHHHHHHHHHHHHHBBBH
HHHHHHHHBMMBHBBBBHHHHHHHHHSrss25SirrsiSiissssiiSsrssr;rS2Siisi;rsiS5sssii53hG&&3i9&HHHHHHHHHHHHHHHHHHHHHHBBBBH
HHHHHHHHBMMBBBBBBHHHHHHHHHAissS2Ssrr;;riissssSSissss;;si55isrssiiirrrsiiS23hGh&329&HHHHHHHHHHHHHHHHHHHHHHHBBBH
HHHHHHHHBMMBBBBHHHHHHHHHHHASrsi55isrr;r;r;rrrr;rrssrr;ri55Ssrrr;rrrrrsiiS23h&G939hAHHHHHHHHHHHHHHHHHHHHHHHBBBH
HHHHHHHHBMMBBBBBHHHHHHHHHHHAirS25isrr;;;;;rrr;;;ssrsr;ri55SSr;;;;;rsssiSS29G&h39hHHHHHHHHHHHHHHHHHHHHHHHHBBBBH
HHHHHHHHBMMBBBBBHHHHHHHHHHHHhr;25issrrrr;;;;:,,;ssssrrsi525Sr:::;;rrsiSS52hGGh9&HHHHHHHHHHHHHHHHHHHHHHHHHBBBBB
HHHHHHHHBMBBBBBBBBHHHHHHHHHHHX;25iissrr;::,,,,;;iissrrri5555S;::;rrsiiS5529GGhhHHHHAAHHHHHHHHHHHHHHHHHHHBBBBBH
HHHHHHHHBMMBBBBBHHHHHHHHHHHHHAs22Siisrrr;:::;rrriissr,;si5S52i;rrrsiiS52XX9GGhHHHHHAHHHHHHHHHHHHHHHHHHHHHHBHBH
AHHHHHHHBMBBBBBBHHHHHHHHHHHHHH352SSiissrr;;rssrsissSsssiX5529Ssrsssii552XX9GAHHHHHHHHHHHHHHHHHHHHHHHHHHHBBBBBH
HHHHHHHHBBMBBBBBHHHHHHHHHHHHHHH&25SSiisssssiirrrsXh3XXXhGG99XisrsssiS555X39GHHHHHHHAHHHHHHHHHHHHHHHHHHHBBHBHBH
HHHHHHHHBBMBBBBHBHHHHHHHHHHHHHHH55SSSissssississsiissSSiiSSiSSSSSiiiiiS5X39&HHHHHHHHHHHHHHHHHHHHHHBHHHBBBBBHBH
AHHHHHHHBBMBBHBBHHHHHHHHHHHHHHHH35iiissssiSSSsssrsr;sssrrsiiiiS5iSiisiS5X39AHHAHHHHHHHHHHHHHHHHHHHHHBBHBBBBBBH
HHHHHHHHBBMMBBBBHHHAHHHHHHHHHHHHH5SiisrriiiSSsssiSSSsrri5XXXX22X5Ssrsi5X33hHHHHHHHHHHHHHHHHHHHHHHHHHHBHHHBBBBB
HHHHHHHHBBMMBBBHHHHAHHHHHHHHHHHHH25SiirrriSsi9HG3;s;iS22i5rr5H2rrr;;ri2333&HHHHHHHHHHHHHHHHHHHHHHHHHHHBHBBBBBH
HHHHHHHHHBMBBBBBHHHHHHHHHHHHHHHHHA55SSsssssrr;i5is:,:,:,:ri222irrrrss5X33hHHHHHHHHHHHHHHHHHHHHHHHBHBHBHBBBBBBH
HHHHHHHHBBMBBBBBHHHAHHHHHHHHHHHHHH25SSissrsr;rri5SiiS55SiS5XX5isisssSX33h&HHHHAHHHHHHHHHHHHHBHHHHHHHBBHBBBBBBB
HHHHHHHHBBMBBBBBHHHAAHHHHHHHHHHHHHH25SSSissssrr;sSSisi5iS2X2XSsiiisS53X9&GHHHHHHHHHHHHHHHHHHHBHHBHBHBBBBBBHBBH
HHHHHHHHHBMBBBBHHHHAHHHHHHHHHHHHHHHHX2Siiisssrr;siiSSSS522X5SsiSSiS53X9GGGHHHHHHHHHHHHHHHHHHHHHHHHHHBHBBBBBBBB
HHHHHHHHBBMMBBBHHHHHHHHHHHHHHHHHHHHH5X5SSSisssrrrrrssSiSSSiisss55S2XX9&&GGGHHHHHHHHHHHHHHHHHHHHHHHBBHBBBBBBBBH
HHHHHHHHBBBMBBBHHHHAHHHHHHHHHHHHHHHH55X25SSSiirr;;;;:;;;ssrrri552X339&&GGGGGMHHHHHHHHHHHHHHHHHHHBBHHHBHBBBBBBH
HHHHHHHHBBMMBBBBHBHHHHHHHHHHHHHHHHHG5S5X32522SSsrr;;:;;srrrri52X999&&&GGGhh9GBBHHHHAHHHHHHHHHHHHHHHBBHBBBBBBBB
HHHHHHHHBBMBBBBBHHHAHHHHHHHHHHHHAHHSiiS5293XX32SisrrrsrrrriS2X9&GG&&&GG93XX22B2AHHHHHHHHHHHHHBBHBBBHBBBBBBBBBB
HHHHHHHHHBMMBBBHBHHHHHHHHHHHHAAAAA9iiiiS5233XXXhX2SSSSiiSS2X9GA&&&&&G9X2555SXBHHHHHHAHHHHHHHHHHHHBBHBBBBBBBBBB
HHHHHHHHHBMMBBBBHBHHHHHHHAHAAAAAhHssssiii55239XXX3G&G&&&&A&A&&&&&&Gh2SSSiiSSHBHHHHHHHHHHHHHHHHHBBHHBBBBBBBBBBB
BHHHHHHHBBMMBMBBBBHAHHHAHHAAAAHAAAssrrrsiiiS5523GGh93399hGGA&&&&h3XSssiiii9HHHHHAHAAHHBBBHHHHHHBBBBBBBBBBMBBBB
BHBHHHHHBBMMMBBHAHHAHHHAHHAAAAAAHGrrrrrrssssiSSSiiSS5X9GGGGh3XX25isrssss&AHHHHHHHAAHHHBBBHHHHHHHBBBBBBBBBBBBBB
BHBHHHHHBBMBBAAHAHHHHAAHHAAHAAHAHHAsrrrrrrrrrsSSSiiiiSSSSSSSSSssrrrrshHHHHHHHAAAHAHHHHHHHHHHHHHHHHBBBBBBBBBBBB
BBHBHHHHBBBAAHHHHHHHHHHHHHHAHAAA&HAAAXr;;;;;r;rsiS55225SSis;rrrrrs&AAHHHHAAHBAAHHHHHHHBHHHHHHHHHHHHHBBBBBBBBBB
BHBHHHBBAAAAHHHHHAHHAAAHAHAHAAAAAAAAAHAAA9s;;;;rrrssssr;;;;i3&AAAHHAAAAAAAAHHHHHHHHHHHHHHHHHHHHBBHHBHHHBBBBBBB
BHHBHHAAAAHAAAAAAAAAAHAHAHAHHAA&BHAAAAHHAAAAAAAA&AAAAAAAAAAAAHAAAHAAAAHAHAABHHHHHHHHHHHHHHHHHHHBHHBHHBHHHBMBBB
BBBAHHHHHHHAHAHHHAHHHHHHHHHHHAAABAAAAAAAAAHAAAAAAAAAAAAAAAAAAHAAAAAAAAAHHHHBHHHHHHHHHHHHHHHHHHHHHHHHHHHHBHHBBB
HHHHHHHHHHHHHHHHHHHAAHHAHAHHHHHAHHAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHAAAAAHAHHHHHHHHHHHHHHHHHHHHHAHHHHHHHHHHHHHHHHM
HHHHHHHHHAAHAAAAAAAAAAAAHHAAAAA&HAAAAAHAAAAAAAAAAAAAAAAAAAHAAHAAAAAHHHAHHAHHHHHAHHHHHHHHHHHHAAAAAHHHHHHHHBBHHH
HHHHHAAAAAAAAAAAAAAAAAAAAAAAAAAAHAAAAAAAAAAAAAAAAAAAHAAAAAAAAAHHAAHHHAHHAABHHHHAHHHHHHHHHHHHHAAAAAAAHHHHHHBHHB
HHHHHHHHAAAAAAAAAAAAAAAAAAAAAAAAHAAAAAAAAAAAAAAAHAAAAAAAAAAHHAAAAAAAHAAHHABHHAAAAHHHHHHHHHHHHHAAAAAHHHHHHHHHHB
HHHHHHHHHHAHAHAAAAAAAAAHAAHHHAAAHAAAHAAAAAAAAAAAAAAAAAAAAAAAAAAAAHHHAHAAHAAAHAAAAAHAAHHBHHHHHHAAAHAHAHHHHHHBB
 * */

vector <vector <int>> edges;
vector <bool> visited;
vector <int> toppleSort;

void dfs (int v) {
    visited[v] = 1;
    for (int i = 0; i < edges[v].size(); i++) {
        if (edges[v][i] && !visited[i]) {
            dfs(i);
        }
    }
    toppleSort.push_back(v);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    edges.resize(n, vector <int> (n, 0));
    visited.resize(n, 0);
    string trash;
    getline(cin, trash);
    for (int i = 0; i < n; i++) {
        getline(cin, trash);
        for (int j = 0; j < i; j++) {
            if ((int)trash[j] - '0') {
                edges[i][j] = 1;
            } else {
                edges[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        dfs(i);
        if (edges[toppleSort[0]][toppleSort[toppleSort.size() - 1]]) {
            break;
        } else {
            toppleSort = vector <int> ();
            visited = vector <bool> (n, 0);
        }
    }

    reverse(toppleSort.begin(), toppleSort.end());
    for (int i = 0; i < toppleSort.size(); i++) {
        cout << toppleSort[i] + 1 << " ";
    }

//    for (int i = 0; i < edges.size(); i++) {
//        for (int j = 0; j < edges.size(); j++) {
//            cout << edges[i][j] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}
