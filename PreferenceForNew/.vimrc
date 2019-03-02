set nocompatible
set autoindent
set cindent
set smartindent
set wrap
set wrapscan
set nobackup
set visualbell
set tabstop=4
set shiftwidth=4
set ruler
set number
set background=dark
set hlsearch
set title
set history=1000
set autowrite
set showmatch
set magic

filetype on
syntax on

au BufReadPost *
\if line("'\"")>0 && line("'\"")<=li
\exe "norm g'\""|
\endif
