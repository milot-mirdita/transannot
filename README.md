# TransAnnot - a transcriptome annotation pipeline
TransAnnot predicts protein functions, orthologous relationships and biological pathways for the whole newly sequenced transcriptome.
It uses MMseqs2 reciprocal best hit to obtain closest homologs from UniProtKB database (or user defined database) and infer protein function, structure and orthologous groups based on the identified homologs.
Prior to functional annotation, it can perform transcriptome sequence assembly using PLASS (Protein-Level ASSembler) to assemble raw sequence reads on protein level upon user request.

## Input
Possible inputs are:

* assembled transcriptomes (obtained e.g. using Trinity) or raw transcriptome reads, which will be assembled at protein level using `plass`
* metatranscriptomes
* single-organism transcriptomes, in such case it is possible to check for the contamination with `contamination` module, which is based on MMseqs2 taxonomy workflow

## Running

### Modules

* `assembly`            It assembles raw sequencing reads to large genomic fragments (contigs)
* `annotate`            It finds homologs for assembled contigs in the custom defined protein seqeunce database (default UniProtKB) using _reciprocal-best hits_ (rbh module) search from MMseqs2 suite
* `contamination`       It checks contaminated contigs using _easy-taxonomy_ module from MMseqs2 suite. This approach uses taxonomy assignments of every contig to identify contamination
* `createdb`            It creates a database from the sequence space (obtained from `downloaddb` module) in a required format for MMseqs2 rbh module
* `downloaddb`          It downloads the user defined database that serves as a search space for homology detection

### Dowloading databases

In this step, sequence database for homology search will be downloaded.
Default database is UniProtKB and can be obtained using a below command:

    transannot downloaddb UniProtKB <outDB> <tmp> [options]
    
To see other options for your choice, please use the below command:

    mmseqs databases -h

and use the below command to download the preferred database (ensure the same keyword as given in `mmseqs database -h`):

    transannot downloaddb <selection> <outDB> <tmp> [options]

### Annotate workflow

`annotate -h` provides details on sequence type and databases acceptable for the `annotate` module. 

### Contamination

Contamination module checks for the contamination in the transcriptomic data. It uses MMseqs2 _easy-taxonomy_ module.

    transannot contamination <Input.fasta> <targetDB> <outPath> <tmp> [options]
 
You can find the report of taxonomy assignments in `outPath` folder.

### tmp folder

`tmp` folder keeps temporary files. By default, all the intermediate output files from different modules will be kept in this folder. To clear `tmp` pass `--remove-tmp-files` parameter.
