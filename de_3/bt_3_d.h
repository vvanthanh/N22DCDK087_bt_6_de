 void showAll(ostream& outDev) {
    for (absList* temp = this; temp; temp = temp->subLst) {
        outDev << temp->dataId << " ";
    }
        outDev << endl;
        return;
}
