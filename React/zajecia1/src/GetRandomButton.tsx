// @flow
import * as React from 'react';
import {FC} from "react";

type Props = {
    onRandom: (v: number) => void;
    max?:number;
};

export const GetRandomButton : FC<Props> = ({onRandom, max = 1}) => {
    return (
        <button onClick={() => onRandom(Math.random() * max)}>
            Random
        </button>
    );
};