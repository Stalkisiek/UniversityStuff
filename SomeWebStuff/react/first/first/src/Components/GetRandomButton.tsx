import React, {FC} from 'react';

interface GetRandomButtonProps{
    onClick : (nr: number) => void;
    children: React.ReactNode;
}

const randomNumber = (max: number) => {
    return Math.floor(Math.random()*max) + 1;
}

export const GetRandomButton: FC<GetRandomButtonProps> = ({onClick, children}) => {
    return(
        <>
            <button onClick={() => randomNumber(100)}>{children}</button>
        </>
    );
};