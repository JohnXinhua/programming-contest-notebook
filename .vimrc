set ts=4
syntax on
set cindent
set shiftwidth=4
set nu
highlight WhitespaceEOL ctermbg=red guibg=red
match WhitespaceEOL /\s\+$/
set expandtab
set autoindent
set bg=dark
autocmd FileType cpp setlocal tw=80

filetype plugin indent on

map <F6> :!g++ -g % && ./a.out <CR>

map <F4> :!g++ -g % <CR>

map <F2> :w <CR>

map <F12> :!gdb ./a.out <CR>
